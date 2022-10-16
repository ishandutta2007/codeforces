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
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int tc,n,res[MAX],mx[MAX],cnt,ans;
pii x[MAX];
vector<int> v;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    mx[0] = -MOD;
    while(tc--){
    	cin>>n;
    	rep(i,1,n)cin>>x[i].fi>>x[i].se;
    	sort(x+1,x+1+n);
    	ans = cnt = 0;
    	rep(i,1,n){
    		if(mx[i-1]<x[i].fi)++cnt;
    		res[i] = cnt;
    		mx[i] = max(mx[i-1],x[i].se);
		}
		v.clear();
		auto it = v.begin();
		rap(i,n,1){
			it = lower_bound(all(v),-mx[i-1]);
			ans = max(ans, res[i-1] + (int)v.size() - (int)(v.end()-it));
			while(!v.empty() && -v.back()<=x[i].se)v.pob();
			v.pb(-x[i].fi);
		}
    	cout<<ans<<endl;
	}
    return 0;
}