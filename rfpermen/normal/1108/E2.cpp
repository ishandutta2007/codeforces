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
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

ll y[MAX],hs[305];
int n,m,x[MAX],st[MAX],a,b,mn[MAX],mx[MAX],c,d,id,ans;
pii z[305];
map<ll,int> ty;
vector<int> res;

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    a = 1e9, b = -1e9;
    rep(i,1,n)cin>>x[i], a = min(a,x[i]), b = max(b,x[i]);
    ans = b-a;
    hs[0] = 1;
    rep(i,1,m){
    	cin>>a>>b;
    	z[i] = {a,b};
    	hs[i] = hs[i-1]*7;
    	rep(j,a,b)y[j]+= hs[i];
	}
	rep(i,1,n){
		if(!ty.count(y[i]))ty[y[i]] = ++id, st[id] = i, mn[id] = x[i], mx[id] = x[i];
		else 
		a = ty[y[i]],
		mn[a] = min(mn[a],x[i]),
		mx[a] = max(mx[a],x[i]);
	}
	rep(i,1,id)rep(j,i+1,id){
		a = b = 0;
		rep(k,1,m){
			c = z[k].fi<=st[i]&&st[i]<=z[k].se;
			d = z[k].fi<=st[j]&&st[j]<=z[k].se;
			if(c&&d)continue;
			if(c)++a;
			else if(d)++b;
		}
		a+= mx[j]-mn[i], b+= mx[i]-mn[j];
		if(ans<a&&a>b){
			ans = a;
			res.clear();
			rep(k,1,m){
				c = z[k].fi<=st[i]&&st[i]<=z[k].se;
				d = z[k].fi<=st[j]&&st[j]<=z[k].se;
				if(c&&!d)res.pb(k);
			}
		}
		else if(ans<b){
			ans = b;
			res.clear();
			rep(k,1,m){
				c = z[k].fi<=st[i]&&st[i]<=z[k].se;
				d = z[k].fi<=st[j]&&st[j]<=z[k].se;
				if(!c&&d)res.pb(k);
			}
		}
	}
	cout<<ans<<endl;
	cout<<res.size()<<endl;
	for(auto i:res)cout<<i<<' ';
    return 0;
}