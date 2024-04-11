#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 4e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,-1,0,1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int n,x[MAX],y,ans;
vector<int> v;
ll res;

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    auto it = v.begin(), nx = v.begin();
    rep(k,0,24){
    	v.clear(), y = 1<<(k+1);
    	rep(i,1,n)v.pb(x[i]%y);
    	sort(all(v));
    	res = 0;
    	for(it = v.begin(); it!=v.end();){
    		nx = it;
    		++nx;
    		res+= lower_bound(nx,v.end(),y-*it) - lower_bound(nx,v.end(),(y>>1)-*it);
    		res+= v.end() - lower_bound(nx,v.end(),(y|(y>>1))-*it);
    		it = nx;
		}
		if(res&1)ans^= 1<<k;
	}
	cout<<ans<<endl;
    return 0;
}