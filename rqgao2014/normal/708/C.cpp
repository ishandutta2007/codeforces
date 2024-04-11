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
#define lb lower_bound
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define clear(x) memset(x,0,sizeof(x))
using namespace std;
inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}
inline void read(int &x,int &y){read(x),read(y);}
inline void read(int &x,int &y,int &z){read(x),read(y),read(z);}

const int N=400005;
int n,si[N],dp[N],mx[N],mx2[N];
struct node{
	int to,next;
}p[N<<1];
int head[N],tot;
bool ans[N];

inline void add(int x,int y){
	p[++tot]=(node){y,head[x]};head[x]=tot;
	p[++tot]=(node){x,head[y]};head[y]=tot;
}
inline void upt(int &mx,int &mx2,int x){
	if(x>mx) mx2=mx,mx=x;
	else if(x>mx2) mx2=x;	
}
inline int get(int mx,int mx2,int x){
	if(x==mx) return mx2;
	return mx;
}
inline void pre(int x,int fa){
	si[x]=1;
	int maxx=0;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(y==fa) continue;
		pre(y,x);
		si[x]+=si[y];
		dp[x]=max(dp[x],dp[y]);
		maxx=max(maxx,si[y]);
		upt(mx[x],mx2[x],dp[y]);
	}
	if(maxx<=n/2&&n-si[x]<=n/2) ans[x]=1;
	if(si[x]<=n/2) dp[x]=si[x];
}
inline void dfs(int x,int fa,int k){
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(y==fa) continue;
		int t=max(get(mx[x],mx2[x],dp[y]),k);
		if(n-si[y]<=n/2) t=n-si[y];
		dfs(y,x,t);
	}
	if(ans[x]) return;
	if(n-si[x]>n/2){
		if(n-si[x]-k<=n/2) ans[x]=1;
	}
	else{
		for(int i=head[x];i;i=p[i].next){
			int y=p[i].to;
			if(y==fa) continue;
			if(si[y]-dp[y]>n/2) return; 
		}
		ans[x]=1;
	}
}

int main(){
	read(n);
	for(int i=1;i<n;i++){
		int x,y;read(x,y);
		add(x,y);
	}
	pre(1,-1);
	dfs(1,-1,0);
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	puts("");
}