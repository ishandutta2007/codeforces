#pragma GCC optimize("Ofast")
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
ll n,a[55],k;

inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
ll cnt,xxx;
//int zgw[65539];
//ll s[66],size;
ll s[8000500],size;
inline void predfs(int dep, ll val) {
	if (dep>7||dep>n) {
		s[++size]=val;
		return;
	}
	while (1) {
		predfs(dep+1,val); if ((long double)val*a[dep]>1e18) break;
		val*=a[dep];
	}
}
/*inline void dfs(int dep, ll lst) {
//	printf("%d %lld %lld\n",dep,lst,cnt); 
	xxx++;
//	if (!lst) return;
	if (dep>=n) {
		cnt+=lower_bound(s,s+size+1,lst)-s+1;
		return;
	}
	while (lst>0) {
		dfs(dep+1,lst); lst/=a[dep];
		if (cnt>=k) break;
	}
}*/
inline void dfs(int dep, ll lst) {
	if (dep==7) {
		cnt+=upper_bound(s,s+size+1,lst)-s-1;
		return;
	}
	while (lst>0) {
		dfs(dep-1,lst); lst/=a[dep];
		if (cnt>=k) break;
	}	
}
inline bool solve(ll x) { //<=x
	if (n<=7)
	{
		return (upper_bound(s+1,s+size+1,x)-s-1)>=k;
	}
	cnt=0; dfs(n,x); return cnt>=k;
}
int main() { //freopen("1.in","r",stdin);
	read(n); rep(i,1,n) read(a[i]); //rep(i,1,n/2) swap(a[i],a[n-i+1]);
	read(k);
//	s[0]=1; while ((double)s[size]*a[n]<=1e18) {s[size+1]=s[size]*a[n]; size++;}
	predfs(1,1); //printf("size %d\n",size);
	sort(s+1,s+size+1); //rep(i,1,10) printf("%lld ",s[i]); puts("");
//	ll mid=1e18,tmp=solve(mid); printf("\n\n%lld",cnt);
	ll l=1,r=1e18; //printf("%lld\n\n",solve(7));
	while (l<r) {
		ll mid=(l+r)/2; //printf("%lld %lld %lld\n",l,r,mid);
		if (solve(mid)) r=mid; else l=mid+1;
	}
	printf("%lld",l);
	return 0;
}