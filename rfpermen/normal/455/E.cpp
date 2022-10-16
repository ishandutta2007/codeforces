#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

ll n,q,x[MAX],y[MAX],a,b,ans[MAX],tmp;
piii z[MAX];
stack<int> s;
vector<pii> v,qu[MAX];

int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i], y[i] = y[i-1]+x[i];
    cin>>q;
    rep(i,1,q)cin>>a>>b, qu[b].pb({a,i});
    sort(z+1,z+1+q);
    rep(i,1,n){
    	while(!s.empty() && x[s.top()]>=x[i])s.pop(), v.pob();
    	while(!s.empty()){
    		v.pob();
    		tmp = (y[i-1]-y[s.top()])-x[i]*(i-s.top()-1);
    		tmp = tmp/(x[i]-x[s.top()]);
    		if(s.top()-tmp<1 || (!v.empty() && v.back().fi>=s.top()-tmp))s.pop();
    		else {
    			v.pb({s.top()-tmp,s.top()});
    			break;
			}
		}
		s.push(i);
		v.pb({i,i});
		
		for(pii j:qu[i]){
			a = v[lower_bound(all(v),mp((int)(i-j.fi+1),0)) - v.begin()].se;
			ans[j.se] = y[i]-y[a]+(j.fi-(i-a))*x[a];
		}
	}
	rep(i,1,q)cout<<ans[i]<<endl;
    return 0;
}