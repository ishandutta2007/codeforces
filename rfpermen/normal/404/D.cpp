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
const int MAX = 1e6+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,dp[MAX][3];
ll ans;
string s;

ll f(int nw,int ls){
	if(nw==n)return ls!=1;
	if(dp[nw][ls]!=-1)return dp[nw][ls];
	ll ret = 0;
	if(s[nw]=='0' || s[nw]=='?'){
		if(ls==0)ret+= f(nw+1,0);
	}
	if(s[nw]=='1' || s[nw]=='?'){
		if(ls!=1)ret+= f(nw+1,1-(ls==2));
	}
	if(s[nw]=='2' || s[nw]=='?'){
		if(ls==2)ret+= f(nw+1,1);
	}
	if(s[nw]=='*' || s[nw]=='?'){
		if(ls!=0)ret+= f(nw+1,2);
	}
	return dp[nw][ls] = ret%MOD;
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    n = s.size();
    if(s[0]=='2')return cout<<"0\n",0;
    mems(dp,-1);
    if(s[0]=='?')ans = f(1,0) + f(1,1) + f(1,2);
    else if(s[0]=='*')ans = f(1,2);
    else ans = f(1,s[0]-'0');
    cout<<ans%MOD<<endl;
    return 0;
}