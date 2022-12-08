#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#include<sstream>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define FF first
#define SS second
using namespace std;

int n,p[800005],to[200005];
pair<pii,int> a[200005],b[200005];set<pii> s;
char opt[200005];

inline void change(int l,int r,int x,int y,int num){
	if(l==r) {p[num]=y;return;}
	int mid=(l+r)>>1;
	if(x<=mid) change(l,mid,x,y,num<<1); else change(mid+1,r,x,y,num<<1|1);
	p[num]=max(p[num<<1],p[num<<1|1]);
}
inline pii get(int l,int r,int f,int y,int num){
	if(p[num]<=y||r<f) return mp(-1,-1);
	if(l==r)return a[l].FF;
	int mid=(l+r)>>1;
	pii res=get(l,mid,f,y,num<<1);
	if(~res.FF) return res;
	return get(mid+1,r,f,y,num<<1|1);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char s[10];int x,y;
		scanf("%s%d%d",s,&x,&y);x++;y++;
		opt[i]=s[0],b[i]=a[i]=mp(mp(x,y),i);
	}
	sort(a+1,a+n+1);s.clear();
	int last=0;
	for(int i=1;i<=n;i++){
		if(a[i].FF!=a[i-1].FF){to[a[i].second]=i;last=i;}
		to[a[i].SS]=last;
	}
	for(int i=1;i<=n;i++){
		int x=b[i].FF.FF,y=b[i].FF.SS;
		if(opt[i]=='a')
//			printf("%d %d %d\n",x,y,to[i]),
			change(1,n,to[i],y,1),s.insert(mp(x,to[i]));
		else if(opt[i]=='r')
//			printf("%d %d %d\n",x,y,to[i]),
			change(1,n,to[i],0,1),s.erase(mp(x,to[i]));
		else{
			set<pii>::iterator it=s.lower_bound(mp(x+1,0));
			if(it==s.end()){puts("-1");continue;}
//			printf("%d\n",(*it).SS);
			pii ans=get(1,n,(*it).SS,y,1);
//			debug(y);
			if(ans.FF==-1) puts("-1"); else 
			printf("%d %d\n",ans.FF-1,ans.SS-1);
		}
//		printf("%d\n",p[1]);
	}
	return 0;
}