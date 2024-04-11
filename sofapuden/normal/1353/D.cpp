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


void solve(){
	auto cmp = [](pair<int,pi> left, pair<int,pi> right) { if(left.f == right.f){return left.s.f > right.s.f;}else{return left.f < right.f;} };
    priority_queue<pair<int,pi>, std::vector<pair<int,pi>>, decltype(cmp)> pq(cmp);

	int n; cin >> n;
	vi v(n,0);
	pq.push(mp(n,mp(0,n-1)));
	int cur = 1;
	while(!empty(pq)){
		pair<int,pi> p = pq.top();
		pq.pop();
		v[(p.f-1)/2+p.s.f] = cur;
		pair<int,pi> p2 = mp((p.f-1)/2,mp(p.s.f,p.s.f+(p.f-1)/2-1));
		pair<int,pi> p3 = mp(p.f/2,mp(p.s.s-p.f/2+1,p.s.s));
		if(p2.f > 0){
			pq.push(p2);
		}
		if(p3.f > 0){
			pq.push(p3);
		}
		cur++;
	}
	for(int i : v){
		cout << i << " ";
	}
		
	
	

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