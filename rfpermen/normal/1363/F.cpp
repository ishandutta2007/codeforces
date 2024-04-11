#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
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
const int MAX = 2e3+5;
const ll MAX2 = 11;
const ll MOD = 1e12;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int tc,n,m,cnt[128],dp[MAX][MAX],pos[MAX];
string s,t;
bool st;
vector<int> v[128];

int f(int nw,int hit){
	if(nw==-1)return 0;
	if(dp[nw][hit]!=-1)return dp[nw][hit];
	if(s[nw]==t[nw+hit])return dp[nw][hit] = f(nw-1,hit);
	if(hit)return dp[nw][hit] = min(f(nw,hit-1),f(nw-1,hit+1)+(v[s[nw]][pos[nw]]<=nw+hit ? 1 : MAX));
	return dp[nw][hit] = f(nw-1,hit+1)+(v[s[nw]][pos[nw]]<=nw+hit ? 1 : MAX);
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n>>s>>t;
    	memset(cnt,0,sizeof cnt);
    	for(auto i:s)cnt[i]++;
    	for(auto i:t)cnt[i]--;
    	st = 1;
    	rep(i,0,127)if(cnt[i]!=0)st = 0;
    	if(!st){
    		cout<<"-1\n"; continue;
		}
		--n;
		rep(i,0,127)v[i].clear();
		rep(i,0,n){
			pos[i] = cnt[s[i]]++;
//			db(pos[i]);
			v[t[i]].pb(i);
		}
		rep(i,0,n)rep(j,0,n)dp[i][j] = -1;
		cout<<f(n,0)<<endl;
	}
	return 0;
}