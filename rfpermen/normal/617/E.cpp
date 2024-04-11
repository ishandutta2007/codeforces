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
//#define sf se.fi
//#define ss se.se
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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<pii,int>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
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

int n,q,k,x[MAX],le,ri,ls;
ll ans[MAX],nw;
unordered_map<int,int> cnt;
ari(3) y[MAX];

bool cmp(ari(3) a,ari(3) b){
	if(a[0]/block==b[0]/block)return a[1]<b[1];
	return a[0]<b[0];
}

inline int que(int x){
	return cnt.count(x) ? cnt[x] : 0;
}

int main(){
//	cout<<fixed<<setprecision(5);
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>q>>k;
	rep(i,1,n)cin>>x[i], x[i]^= x[i-1];
	rep(i,1,q)cin>>y[i][0]>>y[i][1], y[i][2] = i, --y[i][0];
	sort(y+1,y+1+q,cmp);
	ls = -1;
	rep(i,1,q){
		if(y[i][0]/block!=ls){
			ls = y[i][0]/block;
			nw = 0;
			cnt.clear();
			le = ri = y[i][0];
			cnt[x[le]]++;
		}
		while(ri<y[i][1]){
			++ri;
			nw+= que(x[ri]^k);
			++cnt[x[ri]];
		}
		while(le>y[i][0]){
			--le;
			nw+= que(x[le]^k);
			++cnt[x[le]];
		}
		while(le<y[i][0]){
			--cnt[x[le]];
			nw-= que(x[le]^k);
			++le;
		}
		ans[y[i][2]] = nw;
	}
	rep(i,1,q)cout<<ans[i]<<endl;
	return 0;
}