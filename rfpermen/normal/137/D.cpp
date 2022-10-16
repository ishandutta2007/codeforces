#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
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
#define endl "\n"
const int MAX = 5e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,k,pre[MAX][MAX],dp[MAX][MAX],cnt,len,sz;//[MAX]
string s,t;

int f(int le,int rem){
	if(le>n)return dp[le][rem] = 0;
	if(!rem)return dp[le][rem] = pre[le][n];
	if(dp[le][rem]!=-1)return dp[le][rem];
	int ret = 1e9;
	rep(ri,le,n)ret = min(ret,f(ri+1,rem-1)+pre[le][ri]);
	return dp[le][rem] = ret;
}

void bt(int le,int rem){
	if(le>n)return;
	if(!rem){
		t = "";
		rep(i,le,n)t.pb(s[i]);
		len = (n-le)>>1, sz = n-le;
		rep(i,0,len)if(t[i]!=t[sz-i])t[sz-i] = t[i];
		cout<<t<<endl;
		return;
	}
	rep(ri,le,n){
		if(dp[ri+1][rem-1]+pre[le][ri]==dp[le][rem]){
			t = "";
			rep(i,le,ri)t.pb(s[i]);
			len = (ri-le)>>1, sz = ri-le;
			rep(i,0,len)if(t[i]!=t[sz-i])t[sz-i] = t[i];
			cout<<t;
			if(ri!=n)cout<<'+';
			else cout<<endl;
			bt(ri+1,rem-1);
			break;
		}
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>k;
    memset(dp,-1,sizeof dp);
    n = s.size();
    s = 'a'+s;
    rep(i,1,n)rep(j,i,n){
    	cnt = 0;
    	len = (j-i)>>1;
    	rep(o,0,len)if(s[i+o]!=s[j-o])++cnt;
    	pre[i][j] = cnt;
	}
	cout<<f(1,k-1)<<endl;
	bt(1,k-1);
	return 0;
}