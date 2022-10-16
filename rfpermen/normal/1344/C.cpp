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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000000;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
int n,m,cnt[MAX],ans[MAX],hit,a,b,dp[MAX][2];
vector<int> v[MAX],u[MAX];
stack<int> s;

int f(int nw,bool st){
	if(dp[nw][st]!=-1)return dp[nw][st];
	int &ret = dp[nw][st];
	ret = nw;
	if(st)for(auto i:v[nw])ret = min(ret,f(i,st));
	else for(auto i:u[nw])ret = min(ret,f(i,st));
	return ret;
}

int main(){
	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,m){
    	cin>>a>>b;
    	ans[max(a,b)] = 1;
    	++cnt[b];
    	v[a].pb(b);
    	u[b].pb(a);
	}
	rep(i,1,n)if(!cnt[i])s.push(i);
	while(!s.empty()){
		a = s.top(); s.pop();
		for(auto i:v[a]){
			--cnt[i];
			if(!cnt[i])s.push(i);
		}
	}
	rep(i,1,n)if(cnt[i])return cout<<"-1\n",0;
	memset(dp,-1,sizeof dp);
	rep(i,1,n){
		f(i,0), f(i,1);
		ans[i] = (i>dp[i][0])|(i>dp[i][1]);
		if(!ans[i])++hit;
	}
	cout<<hit<<endl;
	rep(i,1,n)cout<<(ans[i]?'E':'A');
	cout<<endl;
	return 0;
}