#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 5e2+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 500;

int n,m,dp[MAX][MAX],x[MAX];
ll md;
string s;

ll f(int a,int b){
	if(a<0||b<0)return 0;
	if(!a && !b)return 1;
	if(dp[a][b]!=-1)return dp[a][b];
	return dp[a][b] = (f(a-1,b)*a*b + (f(a,b-2)*b*(b-1) + f(a-2,b+2)*a*(a-1) >> 1))%md;
}

int main(){
//	cout<<fixed<<setprecision(9);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>md;
    int a,b;
    a = b = 0;
    rep(i,1,m){
    	cin>>s;
    	rep(j,1,n)if(s[j-1]=='1')++x[j];
	}
	rep(i,1,n){
		if(x[i]==1)++b;
		else if(x[i]==2)++a;
	}
	mems(dp,-1);
	cout<<f(n-a-b,b)<<endl;
	return 0;
}