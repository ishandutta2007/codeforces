#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = l;i <= r;++i)
using std::cin;
using std::cout;
const int N = 100100,M=N*20;
int s[M][4],tot=1;
inline void ins(const char*v,const char*d){ int x=1; for(;v!=d&&*v;++v) x=s[x][*v&3]?:s[x][*v&3]=++tot; }
typedef long long ll;
ll n;
char t[N];

struct mat { ll a[4][4]; } start;
inline mat mul(const mat & x, const mat & y) {
	mat res; 
	rep(i, 0, 3) rep(j, 0, 3) res.a[i][j] = 4e18;
	rep(i, 0, 3) rep(j, 0, 3) rep(k, 0, 3)
		res.a[i][k] = std::min(res.a[i][k], x.a[i][j] + y.a[j][k]);
	return res;
}
inline ll min(const mat & x) {
	ll res = 4e18;
	rep(i, 0, 3) rep(j, 0, 3) res=std::min(res,x.a[i][j]);
	return res;
}
void dfs(int x,ll*a,int d){
	rep(i,0,3)
	if(s[x][i])dfs(s[x][i],a,d+1);
	else a[i]=std::min<ll>(a[i],d);
}
mat pw[100];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> t + 1;
	int len = strlen(t + 1);
	rep(i,1,len)ins(t+i,t+i+21);
	rep(i,0,3){
		rep(j,0,3)pw->a[i][j]=4e18;
		if(s[1][i])dfs(s[1][i],pw->a[i],1);
	}
	for(int i = 1;i < 63;++i) pw[i] = mul(pw[i - 1], pw[i - 1]);
	ll ans=1;
	rep(i,0,3)rep(j,0,3)if(i^j)start.a[i][j]=4e18;
	for(int i = 62;i >= 0;--i)  {
		if(min(mul(start,pw[i]))<n) {
			ans+=1ll<<i,start=mul(start,pw[i]);
		}
	}
	cout<<ans<<'\n';
}