#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

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

#define vt vector
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
#define EACH(x, a) for (auto& x: a)

template<class T> void read(T &x){ cin >> x; }
template<class A> void read(vt<A> &v){ EACH(x, v) read(x); }
template<class H, class... T> void read(H& h, T& ...t){ read(h); read(t...); }

str to_string(const char* c){ return (str)c; }
str to_string(char c){ return (str)""+c; }
str to_string(str s){ return s; }
str to_string(bool b){ return b?"True" : "False"; }
template<class A> str to_string(vt<A> v){ str s; EACH(x, v) s+= to_string(x) + " "; return s; }
template<class H, class... T> str to_string(H& h, T& ...t){ str s; s+=to_string(h); s+=" "; s+=to_string(t...); return s; }
void print(str s){ cout << s << "\n"; }
template<class... A> void print(A ...a){ print(to_string(a...)); }


int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); }
str tb(int x) {str ans; int c = x; for(int i = log2(x); i >= 0; --i){if(pow(2,i) <= c){ ans += "1"; c-=pow(2,i); } else { ans += "0"; } } return ans;}
bool ispr(int x){if(x <= 1){return false;} for(int i = 2; i <= sqrt(x); ++i){ if(x%i == 0){ return false; } }return true; } 
			
const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18;

//tree<int,null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> T;

void solve(){
	ll n1, n2, n3, n4; cin >> n1 >> n2 >> n3 >> n4;
	vl v1(n1), v2(n2), v3(n3), v4(n4);
	read(v1,v2,v3,v4);
	ll m1; cin >> m1;
	set<pair<ll,ll>> S1, S2, S3;
	for(int i = 0; i < m1; ++i){
		ll a, b; cin >> a >> b;
		S1.insert({a-1,b-1});
	}
	ll m2; cin >> m2;
	for(int i = 0; i < m2; ++i){
		ll a, b; cin >> a >> b;
		S2.ins({a-1,b-1});
	}
	ll m3; cin >> m3;
	for(int i = 0; i < m3; ++i){
		ll a, b; cin >> a >> b;
		S3.ins({a-1,b-1});
	}
	std::priority_queue<pair<ll,ll>> pq1, pq2, pq3, pq4;
	for(int i = 0; i < n1; ++i){
		pq1.push({-v1[i],i});
	}
	for(int i = 0; i < n2; ++i){
		vector<pair<ll,ll>> nogo;
		auto x = pq1.top();
		bool ok = 1;
		while(S1.count({x.s,i})){
			nogo.pb(x);
			pq1.pop();
			if(pq1.empty()){ok = 0;break;}
			x = pq1.top();
		}
		if(ok)pq2.push({x.f-v2[i],i});
		for(int j = 0; j < (int)nogo.size(); ++j){
			pq1.push(nogo[j]);
		}
	}
	if(pq2.empty()){
		cout << -1 << "\n";
		return;
	}
	for(int i = 0; i < n3; ++i){
		vector<pair<ll,ll>> nogo;
		auto x = pq2.top();
		bool ok = 1;
		while(S2.count({x.s,i})){
			nogo.pb(x);
			pq2.pop();
			if(pq2.empty()){ok = 0;break;}
			x = pq2.top();
		}
		if(ok)pq3.push({x.f-v3[i],i});
		for(int j = 0; j < (int)nogo.size(); ++j){
			pq2.push(nogo[j]);
		}
	}
	if(pq3.empty()){
		cout << -1 << "\n";
		return;
	}
	for(int i = 0; i < n4; ++i){
		vector<pair<ll,ll>> nogo;
		auto x = pq3.top();
		bool ok = 1;
		while(S3.count({x.s,i})){
			nogo.pb(x);
			pq3.pop();
			if(pq3.empty()){ok = 0;break;}
			x = pq3.top();
		}
		if(ok)pq4.push({x.f-v4[i],i});
		for(int j = 0; j < (int)nogo.size(); ++j){
			pq3.push(nogo[j]);
		}
	}
	if(pq4.empty()){
		cout << -1 << "\n";
		return;
	}
	auto z = pq4.top();
	cout << -z.f << "\n";
}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	bool isT = 0;
	if(isT){
		int t; cin >> t; while(t--){
			solve();
		}
		return 0;
	}
	solve();		
	return 0;
}