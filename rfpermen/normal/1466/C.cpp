#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;
 
int tc,n,dp[2][26][26],x[MAX],ans,tmp;
string s;
bool nw,ls;

int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>s;
    	n = 0;
    	for(char c:s)x[++n] = c-'a';
    	if(n==1){
    		cout<<"0\n";
		}
		else if(n==2){
			cout<<(x[1]==x[2])<<endl;
		}
		else {
			rep(i,0,25)rep(j,0,25){
				if(i!=j)dp[0][i][j] = (x[1]!=i) + (x[2]!=j);
				else dp[0][i][j] = -1;
			}
			nw = 1, ls = 0;
			rep(i,3,n){
				mems(dp[nw],-1);
				rep(j,0,25)rep(k,0,25)if(dp[ls][j][k]!=-1){
					tmp = dp[ls][j][k];
					if(x[i]!=j && x[i]!=k){
						if(dp[nw][k][x[i]]==-1 || dp[nw][k][x[i]]>tmp)dp[nw][k][x[i]] = tmp;
					}
					rep(o,0,4)if(o!=j && o!=k){
						if(dp[nw][k][o]==-1 || dp[nw][k][o]>tmp+1)dp[nw][k][o] = tmp+1;
					}
				}
				ls^=1, nw^=1;
			}
			ans = n;
			rep(i,0,25)rep(j,0,25)if(i!=j && dp[ls][i][j]!=-1)ans = min(ans, dp[ls][i][j]);
    		cout<<ans<<endl;
		}
	}
    return 0;
}