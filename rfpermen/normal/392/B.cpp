#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
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
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll v[3][3],dp[45][3][3][3];

ll f(int n,int a,int b,int c){
	if(n==1)return v[a][c];
	if(dp[n][a][b][c]!=-1)return dp[n][a][b][c];
	ll ret = min(f(n-1,a,c,b),f(n-1,a,b,c)+f(n-1,c,a,b)) + v[a][c] + min(f(n-1,b,a,c),f(n-1,b,c,a)+f(n-1,a,b,c));
	ret = min(ret,min(f(n-1,a,b,c),f(n-1,a,c,b)+f(n-1,b,a,c)) + v[a][b] + min(f(n-1,c,b,a),f(n-1,c,a,b)+f(n-1,b,c,a)) + v[b][c] + min(f(n-1,a,b,c),f(n-1,a,c,b)+f(n-1,b,a,c)));
	return dp[n][a][b][c] = ret;
}
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    rep(i,0,2)rep(j,0,2)cin>>v[i][j];
    memset(dp,-1,sizeof dp);
    cin>>n;
    cout<<min(f(n,0,1,2),f(n,0,2,1)+f(n,1,0,2))<<endl;
    return 0;
}