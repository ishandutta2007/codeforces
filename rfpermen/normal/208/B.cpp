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
//#define ff fi.fi
//#define fs fi.se
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
const int MAX = 1e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int dp[55][55][55][55],n,x[55];
string a[]={"2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"},s;
string b[]={"S", "D", "H", "C"};
map<string,int> hs;

int f(int nw,int a,int b,int c){
	if(nw==1)return 1;
	int &ret = dp[nw][a][b][c];
	if(ret!=-1)return ret;
	ret = 0;
	if(b%13==c%13 || b/13==c/13)ret|= f(nw-1,x[max(nw-3,0)],a,c);
//	if(nw>=3 && (a%13==c%13 || a/13==c/13))ret|= f(nw-1,x[max(nw-3,0)],c,b);
	if(nw>=4 && (x[nw-3]%13==c%13 || x[nw-3]/13==c/13))ret|= f(nw-1,c,a,b);
	return ret;
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,0,12)rep(j,0,3)hs[a[i]+b[j]] = i + j*13;
    cin>>n;
    rep(i,1,n)cin>>s, x[i] = hs[s];
    mems(dp,-1);
    if(n==1)cout<<"YES\n";
    else if(n==2)cout<<(f(2,0,x[1],x[2]) ? "YES" : "NO")<<endl;
    else cout<<(f(n,x[n-2],x[n-1],x[n]) ? "YES" : "NO")<<endl;
    return 0;
}