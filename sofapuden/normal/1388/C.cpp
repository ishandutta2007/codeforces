#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<db,db> pd; 
 
typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<db> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd;
typedef vector<vi> vvi; 

typedef set<int> si;

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound
#define ts to_string 

int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); }
str tb(int x) {str ans; int c = x; for(int i = log2(x); i >= 0; --i){if(pow(2,i) <= c){ ans += "1"; c-=pow(2,i); } else { ans += "0"; } } return ans;}
bool ispr(int x){if(x <= 1){return false;} for(int i = 2; i <= sqrt(x); ++i){ if(x%i == 0){ return false; } }return true; } 

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18;

vi citi;
vvi gra;
vi p, h;
bool ok = 1;

int assi(int pa, int ind){
	int ret = p[ind];
	for(int i = 0; i < sz(gra[ind]); ++i){
		if(gra[ind][i] != pa)ret+=assi(ind, gra[ind][i]);
	}
	citi[ind] = ret;
	return ret;
}

int good(int ind, int pa){
	if((citi[ind]&1) != (h[ind]&1))ok = 0;
	if(citi[ind] < h[ind])ok = 0;
	int x = 0;
	for(int i = 0; i < sz(gra[ind]); ++i){
		if(gra[ind][i] != pa)x+=good(gra[ind][i], ind);
	}
	if(x > ((citi[ind]/2)+((h[ind] > 0)+h[ind])/2))ok = 0;
	return ((citi[ind]/2)+((h[ind] > 0)+h[ind])/2);
}
		
	
	


void solve(){
	int n, m; cin >> n >> m;
	ok = 1;
	p.clear();
	p.resize(n);
	h.clear();
	h.resize(n);
	gra.clear();
	gra.resize(n);
	citi.clear();
	citi.resize(n, -1);
	for(int &i : p)cin >> i;
	for(int &i : h)cin >> i;
	for(int i = 0; i < n-1; ++i){
		int tm1, tm2; cin >> tm1 >> tm2;
		tm1--; tm2--;
		gra[tm1].pb(tm2);
		gra[tm2].pb(tm1);
	}
	assi(-1, 0);
	good(0, -1);
	if(!ok){
		cout << "NO";
		return;
	}
	cout << "YES";
	
	
	
	

}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	bool isT = 1;
	if(isT){
		int t; cin >> t; while(t--){
			solve();
			cout << "\n";
		}
		return 0;
	}
	solve();
	cout << "\n";		
	return 0;
}