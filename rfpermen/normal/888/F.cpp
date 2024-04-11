#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pll>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 500+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
int n;
ll dp[MAX][MAX],mem[MAX][MAX],ans;
bool v[MAX][MAX];
 
ll f(int a,int b){
	if(dp[a][b]!=-1)return dp[a][b];
	if((a-b+n)%n==1)return dp[a][b] = 1;
	ll ret = 0, sb;
	int i = b, j;
	while(1){
		++i;
		if(i==n)i = 0;
		if(i==a)break;
		if(v[a][i]){
			if(mem[i][b]!=-1)sb = mem[i][b];
			else {
				sb = 0;
				j = i;
				while(1){
					--j;
					if(j==-1)j = n-1;
					if(j==b)break;
					if(v[j][b])sb+= f(i,j)*f(j,b);
					sb%= MOD;
				}
				mem[i][b] = sb;
			}
			ret+= f(a,i)*(f(i,b)-sb);
		}
		if(v[b][i])ret+= f(a,i)*f(i,b);
		ret%= MOD;
	}
	if(ret<0)ret+= MOD;
	return dp[a][b] = ret;
}
 
int main(){
//	cout<<fixed<<setprecision(5);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)rep(j,1,n)cin>>v[i-1][j-1];
    memset(dp,-1,sizeof dp);
    memset(mem,-1,sizeof mem);
    rep(i,1,n-1){
    	if(v[0][i]){
    		ans+= f(0,i)*f(i,0)%MOD;
    		v[0][i] = v[i][0] = 0;
		}
	}
	cout<<ans%MOD<<endl;
	return 0;
}