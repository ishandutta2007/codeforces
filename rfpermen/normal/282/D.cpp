#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
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
const int MAX = 3e2+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,dp[MAX][MAX][2];

int f(int a,int b,bool mv){
	if(!a && !b)return mv;
	if(dp[a][b][mv]!=-1)return dp[a][b][mv];
	int mn = min(a,b);
	rep(i,1,a)if(f(a-i,b,mv^1)!=mv)return dp[a][b][mv] = !mv;
	rep(i,1,b)if(f(a,b-i,mv^1)!=mv)return dp[a][b][mv] = !mv;
	rep(i,1,mn)if(f(a-i,b-i,mv^1)!=mv)return dp[a][b][mv] = !mv;
	return dp[a][b][mv] = mv;
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a,b,c;
    cin>>n;
    if(n==1){
    	cin>>a;
    	cout<<(a ? "BitLGM" : "BitAryo")<<endl;
	}
	else if(n==2){
		cin>>a>>b;
		mems(dp,-1);
    	cout<<(f(a,b,0) ? "BitLGM" : "BitAryo")<<endl;
	}
	else {
		cin>>a>>b>>c;
    	cout<<((a^b^c) ? "BitLGM" : "BitAryo")<<endl;
	}
    return 0;
}