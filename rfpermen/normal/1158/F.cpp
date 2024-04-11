#include<iostream>
#include<string.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mems(x,y) memset(x,y,sizeof x)
#define endl '\n'
const int MAX = 3e3+5;
const ll MOD = 998244353;
const int block = 11;
inline ll pw(ll x,ll y){ll ret=1;while(y){if(y&1)ret=ret*x%MOD;x=x*x%MOD,y>>=1;}return ret;}
inline void add(int &a,int b){a=a+b>=MOD?a+b-MOD:a+b;}
 
int n,c,x[MAX],cnt[MAX];
ll pre[MAX],inv[MAX],num[MAX][MAX],ans[MAX];
 
int main(){
//	cout<<fixed<<setprecision(10);
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,1,3000){
    	pre[i] = ((pre[i-1]+1<<1)-1)%MOD;
    	inv[i] = pw(pre[i],MOD-2);
	}
	cin>>n>>c;
	rep(i,1,n)cin>>x[i];
	
	if(c>block){
		static int dp[MAX][MAX];
		ll pd,tot;
		rep(i,1,n){
			pd = tot = 1;
			mems(cnt,0);
			rap(j,i,1){
				if(x[i]!=x[j]){
					tot+= !cnt[x[j]];
					++cnt[x[j]];
					if(cnt[x[j]]>1)pd = pd*inv[cnt[x[j]]-1]%MOD;
					pd = pd*pre[cnt[x[j]]]%MOD;
				}
				if(tot==c)num[i][j] = pd;
			}
		}
		dp[0][0] = 1, ans[0] = pre[n];
		int bt;
		rep(i,1,n){
			bt = i/c;
			rep(j,1,bt){
				tot = 0;
				rap(k,i-c,0)tot+= dp[j-1][k]*num[i][k+1]%MOD;
				dp[j][i] = tot%MOD;
				ans[j]+= dp[j][i]*(pre[n-i]+1)%MOD;
			}
		}
		rep(i,0,n)printf("%lld ",((ans[i]-ans[i+1])%MOD+MOD)%MOD);
	}
	else {
		static int dp[2][1<<block][MAX];
		bool nw=1,ls=0;
		int en = (1<<c)-1, bt, mask;
		dp[0][0][0] = 1;
		bool z;
		rep(i,1,n){
			bt = i/c;
			rep(j,0,en)rep(k,0,bt)dp[nw][j][k] = dp[ls][j][k];
			rep(j,0,en){
				mask = j|(1<<x[i]-1), z = false;
				if(mask==en)mask = 0, z = true;
				rep(k,0,bt)add(dp[nw][mask][k+z],dp[ls][j][k]);
			}
			nw^=1, ls^=1;
		}
		ll ans;
		rep(i,0,n){
			ans = 0;
			rep(j,0,en)ans+= dp[ls][j][i];
			if(!i)ans+= MOD-1;
			printf("%lld ",ans%MOD);
		}
	}
    return 0;
}