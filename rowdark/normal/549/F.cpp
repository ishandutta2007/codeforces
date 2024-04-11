#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>
#include<ctype.h>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<unordered_map>
#include<stack>
#include<queue>
#include<cmath>
#include<bitset>
#include<iomanip>
#include<complex>
#include<utility>

#define X first
#define Y second
#define REP_0(i,n) for(int i=0;i<(n);++i)
#define REP_1(i,n) for(int i=1;i<=(n);++i)
#define REP_2(i,a,b) for(int i=(a);i<(b);++i)
#define REP_3(i,a,b) for(int i=(a);i<=(b);++i)
#define REP_4(i,a,b,c) for(int i=(a);i<(b);i+=(c))
#define DOW_0(i,n) for(int i=(n)-1;-1<i;--i)
#define DOW_1(i,n) for(int i=(n);0<i;--i)
#define DOW_2(i,a,b) for(int i=(b);(a)<i;--i)
#define DOW_3(i,a,b) for(int i=(b);(a)<=i;--i)
#define FOREACH(a,b) for(typeof((b).begin()) a=(b).begin();a!=(b).end();++a)
#define RFOREACH(a,b) for(typeof((b).rbegin()) a=(b).rbegin();a!=(b).rend();++a)
#define PB push_back
#define PF push_front
#define MP make_pair
#define IS insert
#define ES erase
#define IT iterator
#define RI reserve_iterator
#define PQ priority_queue
#define LB lower_bound
#define UB upper_bound
#define ALL(x) x.begin(),x.end()

using namespace std;

typedef long long LL;

int n,m;

int sum[300101];
int fa[300101];
bool vis[300101];
int pre[300101];
int nxt[300101];
inline int getfa(int x){
	int y=x,z;
	while(y!=fa[y]) y=fa[y];
	while(x!=y){
		z=fa[x];
		fa[x]=y;
		x=z;
	}
	return y;
}

unordered_map<int,int> M[300101];

unordered_map<int,int>::IT iter;
vector<pair<int,int> > V;
inline void merge(unordered_map<int,int> &A,unordered_map<int,int> &B){
	if(A.size()<B.size()) A.swap(B);
	for(iter=B.begin();iter!=B.end();++iter) if(iter->second) A[iter->first]+=iter->second;
	B.clear();
}

inline void myread(int &x){
register int y;
x=0;
while(isdigit(y=getchar())) x=x*10+y-'0';
}

int main(){
myread(n),myread(m);
//	srand(unsigned(time(NULL)));
//	n=300000;
//	m=rand();
	REP_1(i,n){
		int x;
myread(x);
//		x=rand();
		V.push_back(make_pair(x,i));
		fa[i]=i;
		x%=m;
		sum[i]=sum[i-1]+x;
		if(sum[i]>=m) sum[i]%=m;
		nxt[i]=sum[i];
		pre[i]=sum[i-1];
	}
	sort(V.begin(),V.end());
	LL ans=0;
	REP_0(i,n){
		int f=V[i].first%m;
		int x=V[i].second;
		vis[x]=1;
		int y=0,z=0;
		if(vis[x-1]){
			y=getfa(x-1);
			if(M[y].count(sum[x-1]))
			ans+=M[y][sum[x-1]];
			if(pre[y]==sum[x-1]) ++ans;
		}
		if(vis[x+1]){
			z=getfa(x+1);
			if(M[z].count(sum[x]))
			ans+=M[z][sum[x]];
			if(nxt[z]==sum[x]) ++ans;
		}
		unordered_map<int,int> &now=M[x];
		unordered_map<int,int> &pree=M[y];
		unordered_map<int,int> &nxtt=M[z];
		if(y&&z){
			int v;
			if(pree.size()<nxtt.size()){
				for(iter=pree.begin();iter!=pree.end();++iter)if(iter->second){
					v=iter->first+f;
					if(v>=m) v-=m;
					if(nxtt.count(v))
					ans+=(LL)nxtt[v]*iter->second;
				}
			}
			else{
				for(iter=nxtt.begin();iter!=nxtt.end();++iter)if(iter->second){
					v=iter->first-f;
					if(v<0) v+=m;
					if(pree.count(v))
					ans+=(LL)pree[v]*iter->second;
				}
			}
			{
				v=pre[y]+f;
				if(v>=m) v-=m;
				if(nxtt.count(v))
				ans+=nxtt[v];
			}
			{
				v=nxt[z]-f;
				if(v<0) v+=m;
				if(pree.count(v))
				ans+=pree[v];
				ans+=v==pre[y];
			}
		}
		if(y){
			merge(now,pree);
			fa[y]=x;
			++now[pre[x]];
			pre[x]=pre[y];
		}
		if(z){
			merge(now,nxtt);
			fa[z]=x;
			++now[nxt[x]];
			nxt[x]=nxt[z];
		}
	}
	cout<<ans<<endl;
	scanf("%d",&n);
	return 0;
}