#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD2 = 1000000007;
const ll MOD = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll n,m,en,a,b,key,hs[MAX],hss[MAX],x[MAX],y[MAX],tb[MAX],dp[MAX][2];
string s,t;

ll f(int pos,bool st){
	if(pos>n)return 1;
	if(dp[pos][st]!=-1)return dp[pos][st];
	int ret = f(pos+1,st);
	if(st)ret+= f(pos,0);
	else if(tb[pos])ret+= f(tb[pos],1);
	if(ret>MOD2)ret-=MOD2;
	return dp[pos][st] = ret;
}

int main(){
//	cout<<fixed<<setprecision(6);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    key = 36671;
    cin>>s>>t;
    if(t.size()>s.size())return cout<<0,0;
    n = s.size(), m = t.size()-1, s = '1'+s;
    hs[0] = hss[0] = 1;
    rep(i,1,n){
    	x[i] = x[i-1]*key + s[i];
    	y[i] = (y[i-1]*key + s[i])%MOD;
    	hs[i] = hs[i-1]*key;
    	hss[i] = hss[i-1]*key%MOD;
	}
	for(auto i:t)a = a*key + i, b = (b*key + i)%MOD;
	en = n - m;
	rep(i,1,en){
		if	(x[i+m] - x[i-1]*hs[m+1] == a && 
			(y[i+m] - y[i-1]*hss[m+1]%MOD + MOD)%MOD == b)tb[i] = i+m+1;
	}
	rap(i,n,1)if(!tb[i])tb[i] = tb[i+1];
	memset(dp,-1,sizeof dp);
	cout<<(f(1,0)-1+MOD2)%MOD2<<endl;
    return 0;
}