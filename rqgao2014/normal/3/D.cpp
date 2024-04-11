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
#include<ctime>
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
#define debug(x) cout<<#x<<"="<<x<<endl;
#define FF first
#define SS second
using namespace std; 

char s[200005];
int n,m,k,sum[200005],pos[200005],p[800005],flag[800005];
vector<pii> g;

inline void update(int num){
	p[num]=min(p[num<<1],p[num<<1|1]);
}
inline void pushdown(int num){
	if(!flag[num]) return;
	p[num<<1]-=flag[num];p[num<<1|1]-=flag[num];
	flag[num<<1]+=flag[num];flag[num<<1|1]+=flag[num];
	flag[num]=0;
}
inline void change(int l,int r,int x,int y,int num){
	pushdown(num);
	if(l==x&&r==y){
		p[num]-=2;flag[num]+=2;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) change(l,mid,x,min(y,mid),num<<1);
	if(y>mid) change(mid+1,r,max(mid+1,x),y,num<<1|1);
	update(num);
}
inline int get(int l,int r,int x,int y,int num){
	pushdown(num);
	if(l==x&&r==y)return p[num];
	int mid=l+r>>1,res=100000000;
	if(x<=mid) res=min(res,get(l,mid,x,min(y,mid),num<<1));
	if(y>mid) res=min(res,get(mid+1,r,max(mid+1,x),y,num<<1|1));
	return res;
}
inline void build(int l,int r,int num){
	if(l==r){p[num]=sum[l];return;}
	int mid=(l+r)>>1;
	build(l,mid,num<<1);build(mid+1,r,num<<1|1);
	update(num);
}

int main(){
	scanf("%s",s+1);n=strlen(s+1);
	k=n/2;
//	if(s[1]==')') {puts("-1");return 0;}
	for(int i=1;i<=n;i++)
		if(s[i]=='?') m++,pos[m]=i,sum[i]=sum[i-1]+1,s[i]='('; else if(s[i]==')') sum[i]=sum[i-1]-1,k--; else sum[i]=sum[i-1]+1;
	for(int i=1;i<=n;i++)
		if(sum[i]<0){
			puts("-1");return 0;
		}
	build(1,n,1);ll ans=0;
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ans+=x;g.pb(mp(y-x,pos[i]));
	}
	sort(g.begin(),g.end());
	for(int i=0;i<m&&k;i++){
//		printf("%d %d\n",g[i].SS,g[i].FF);
		if(get(1,n,g[i].SS,n,1)>=2){
			change(1,n,g[i].SS,n,1);
			k--;ans+=g[i].FF;
			s[g[i].SS]=')';
		}
	}
	if(k) puts("-1"); else printf("%I64d\n",ans),printf("%s",s+1);
	
}