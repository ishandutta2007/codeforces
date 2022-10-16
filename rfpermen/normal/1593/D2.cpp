#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")

using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=(n);i<=(N);++i)
#define For(i,n,N) for(int i=(n);i< (N);++i)
#define rap(i,n,N) for(int i=(n);i>=(N);--i)
#define rip(i,n,N,V) for(int i=(n);i<=(N);i+=V)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
//#define le left
//#define ri right
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
#define ou3(x,y,z) cout << ">> " << (x) << " " << (y) << " " << (z) << endl
#define mems(x,y) memset(&x,y,sizeof x)
#define memsv(x,y) memset(&x[0], y, sizeof(x[0]) * x.size())
#define popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define rsort(x) sort(x), reverse(x)
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define vi vector<int>
#define vii vector<pii>
#define vl vector<ll>
#define vll vector<pll>
#define ari(x) array<int,x>
#define arll(x) array<ll,x>
#define ard(x) array<double,x>
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e6+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 100;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int tc,n,x[MAX],nw,ans,hit,p[MAX];
set<int> s,nx;
map<int,int> cnt;
vector<pii> v;

void bf(int nw,int x){
	if(nw==v.size()){
		nx.insert(x);
		return;
	}
	bf(nw+1,x);
	rep(i,1,v[nw].se)x*= v[nw].fi, bf(nw+1,x);
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	rep(i,2,2000000)if(!p[i]){
		rip(j,i,2000000,i)p[j] = i;
	}
	
	cin>>tc;
	rep(ntc,1,tc){
		cin>>n;
		s.clear();
		cnt.clear();
		rep(i,1,n){
			cin>>x[i];
			++cnt[x[i]];
		}
		ans = 0;
		for(auto i:cnt){
			if(i.se>=n/2)ans = -1;
		}
		if(ans==-1){
			cout<<ans<<endl;
			continue;
		}
		rep(i,1,n)rep(j,i+1,n)s.insert(-abs(x[i]-x[j]));
		nx.clear();
		int dv;
		for(int k:s){
			k = -k;
			if(k<2)break;
			if(nx.count(k))continue;
			v.clear();
			while(k>1){
				dv = p[k];
				hit = 0;
				while(k%dv==0){
					k/= dv;
					++hit;
				}
				v.pb({dv,hit});
			}
			bf(0,-1);
		}
		ans = 0;
		for(int k:nx){
			k = -k;
			if(!k)break;
			rep(i,1,n){
				hit = 0;
				rep(j,1,n){
					hit+= ((abs(x[i] - x[j])%k) == 0);
				}
				if(hit>=n/2){
					ans = k;
					break;
				}
			}
			if(ans)break;
		}
		if(!ans)ans = 1;
		cout<<ans<<endl;
	}
	return 0;
}