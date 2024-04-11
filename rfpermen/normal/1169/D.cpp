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
const ll MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,res[MAX],k;
ll ans;
bool x[MAX],z;
vector<int> v[2];
string s;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    for(auto i:s){
    	++n, i-='0';
    	x[n] = i, v[i].pb(n);
	}
    rep(i,1,n){
    	res[i] = n+1;
    	z = x[i];
    	auto it = upper_bound(all(v[z]),i);
    	if(it==v[z].end())continue;
    	for(int j = it-v[z].begin(); j<v[z].size(); ++j){
    		k = (v[z][j]-i<<1)+i;
    		if(k>=n+1)break;
    		if(x[k]==z){
    			res[i] = k;
    			break;
			}
		}
	}
	rap(i,n-1,1)res[i] = min(res[i],res[i+1]);
	rep(i,1,n)ans+=n+1-res[i];
	cout<<ans<<endl;
	return 0;
}