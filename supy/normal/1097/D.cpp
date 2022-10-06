#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int mo = 1e9+7;
ll n,k,res;
int dp[10200][56][56];
ll p[666],a[666],len,inv[6666];
void getfa(ll n){
	for(int i=2;1LL*i*i<=n;i++)if(n%i==0){
		len++;p[len]=i;while(n%i==0)n/=i,a[len]++;
	}
	if(n>1)len++,p[len]=n,a[len]=1;
}
void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
void dfs(int dep, ll now){
	if(dep>len){
		res=(res+now)%mo;
		return;
	}
	
	rep(i,0,a[dep]){
		dfs(dep+1,1LL*now*dp[k][a[dep]][i]%mo);
		now=1LL*now*(p[dep]%mo)%mo;
	}
}
int main(){
	scanf("%lld%lld",&n,&k);getfa(n);
	inv[1]=1;rep(i,2,500)inv[i]=1LL*(mo-mo/i)*inv[mo%i]%mo;
	int mx=50;
	rep(i,0,mx)dp[0][i][i]=1;
	rep(i,1,k)rep(j,0,mx){
		int now=0;
		rep(c,0,mx){
			add(now,dp[i-1][c][j]);
			dp[i][c][j]=1LL*now*inv[c+1]%mo;
		}
	}
	dfs(1,1);cout<<(res%mo+mo)%mo;
	return 0;
}