#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=(n);i<=(N);++i)
#define For(i,n,N) for(int i=(n);i< (N);++i)
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
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vll vector<pll>
#define vvl vector<vector<ll>>
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
const int MAX = 5e2+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

#define fbo find_by_order
#define ook order_of_key
#define del(x) erase(op.find_by_order(op.order_of_key(x)))
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> pbds;
pbds op;

int n,cnt,st;
ll ans;
map<int,vector<ari(2)>> tv,th;
vector<ari(4)> v;

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int x1,x2,y1,y2;
	cin>>n;
	rep(i,1,n){
		cin>>x1>>y1>>x2>>y2;
		if(x1>x2)swap(x1,x2);
		if(y1>y2)swap(y1,y2);
		if(x1==x2){
			th[x1].pb({y1,0});
			th[x1].pb({y2,1});
		}
		else {
			tv[y1].pb({x1,0});
			tv[y1].pb({x2,1});
		}
	}
	for(auto i:tv){
		sort(all(i.se));
		for(ari(2) j:i.se){
			if(!j[1]){
				if(!cnt)st = j[0];
				++cnt;
			}
			else {
				--cnt;
				if(!cnt)ans+= j[0] - st + 1, v.pb({st,0,i.fi,0}), v.pb({j[0],2,i.fi,0});
			}
		}
	}
	for(auto i:th){
		sort(all(i.se));
		for(ari(2) j:i.se){
			if(!j[1]){
				if(!cnt)st = j[0];
				++cnt;
			}
			else {
				--cnt;
				if(!cnt)ans+= j[0] - st + 1, v.pb({i.fi,1,st,j[0]+1});
			}
		}
	}
	sort(all(v));
	for(ari(4) i:v){
		if(i[1]==0){
			op.insert(i[2]);
		}
		else if(i[1]==2){
			op.erase(i[2]);
		}
		else {
			ans-= op.ook(i[3]) - op.ook(i[2]);
		}
	}
	cout<<ans<<endl;
	return 0;
}