#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,x[MAX],dp[MAX],ans;
vector<int> v[MAX],fc[MAX];

int f(int pos){
	if(dp[pos]!=-1)return dp[pos];
	int &ret = dp[pos];
	ret = 0;
	auto it = v[0].begin();
	for(auto i:fc[pos]){
		it = upper_bound(all(v[i]),pos);
		if(it!=v[i].end())ret = max(ret, f(*it));
	}
	++ret;
	return ret;
}
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>x[i];
    	for(int j = 2; j*j<=x[i]; ++j){
    		if(x[i]%j)continue;
    		v[j].pb(i);
    		fc[i].pb(j);
    		while(x[i]%j==0)x[i]/=j;
		}
		if(x[i]!=1){
			v[x[i]].pb(i);
			fc[i].pb(x[i]);
		}
	}
//	rep(i,1,100){
//		if(!v[i].empty()){
//			cout<<i<<" = ";
//			for(auto j:v[i])cout<<j<<' '; cout<<endl;
//		}
//	}
	memset(dp,-1,sizeof dp);
	rep(i,1,n)ans = max(ans, f(i));
	cout<<ans<<endl;
    return 0;
}