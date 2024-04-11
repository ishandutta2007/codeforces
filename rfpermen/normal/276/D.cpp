#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
//#define endl "\n"
const int MAX = 1e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

ll a,b,dp[63][2][2][2][2];

ll f(int nw,bool xa,bool xb,bool ya,bool yb){//kalau a=0 harus pilih 1, kalau b=0 harus pilih 0
	if(nw<0)return 0;
	if(dp[nw][xa][xb][ya][yb]!=-1)return dp[nw][xa][xb][ya][yb];
	ll o = 1ll<<nw, ret = 0;
	bool aa = 0,bb = 0;
	if(a&o)aa = 1;
	if(b&o)bb = 1;
	if(o>b)return f(nw-1,xa,xb,ya,yb);
	//a = 0, b = 0;
	if(!aa||(xa&&ya))ret = max(ret,f(nw-1,xa,xb|bb,ya,yb|bb));
	//a = 0, b = 1;
	if((!aa||xa)&&(bb||yb))ret = max(ret,o+f(nw-1,xa,xb|bb,ya|(!aa),yb));
	//a = 1, b = 0;
	if((!aa||ya)&&(bb||xb))ret = max(ret,o+f(nw-1,xa|(!aa),xb,ya,yb|bb));
	//a = 1, b = 1;
	if(bb||(xb&&yb))ret = max(ret,f(nw-1,xa|(!aa),xb,ya|(!aa),yb));
	return dp[nw][xa][xb][ya][yb] = ret;
}

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b;
    memset(dp,-1,sizeof dp);
    cout<<f(62,0,0,0,0)<<endl;
	return 0;
}