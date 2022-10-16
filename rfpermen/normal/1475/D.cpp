#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=(n);i<=(N);++i)
#define FOR(i,n,N) for(int i=(n);i< (N);++i)
#define rap(i,n,N) for(int i=(n);i>=(N);--i)
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
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MOD = 1000000009;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 500;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

ll tc,n,k,x[MAX],z,ans,nw,cnt,sm,id;
vector<ll> a,b;

int main(){
//	cout<<fixed<<setprecision(4);
// freopen("output.txt", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>tc;
	rep(ntc,1,tc){
		cin>>n>>k;
		ans = nw = sm = 0;
		a.clear(), b.clear();
		rep(i,1,n)cin>>x[i], sm+= x[i];
		rep(i,1,n){
			cin>>z;
			ans+= z;
			if(z==1)a.pb(x[i]);
			else b.pb(x[i]);
		}
		if(sm<k){
			cout<<"-1\n";
			continue;
		}
		sort(all(a)), reverse(all(a));
		sort(all(b)), reverse(all(b));
		if(a.empty()){
			cnt = 0;
			for(ll i:b){
				nw+= i;
				cnt+= 2;
				if(nw>=k){
					ans = cnt;
					break;
				}
			}
		}
		else {
			for(ll i:a)nw+= i;
			if(nw>=k)ans = a.size();
			id = 0;
			cnt = a.size();
			while(id!=b.size() && nw<k)nw+= b[id], cnt+= 2, ++id;
			if(nw>=k)ans = min(ans,cnt);
			
			rap(i,a.size()-1,0){
				nw-= a[i];
				--cnt;
				while(id!=b.size() && nw<k)nw+= b[id], cnt+= 2, ++id;
				if(nw>=k)ans = min(ans,cnt);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}