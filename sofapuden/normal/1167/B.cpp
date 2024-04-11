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
	int a, b, c, d, n1, n2, n3, n4, n5, n6;
	cout << "? 1 2\n";
	cout.flush();
	cin >> a;
	cout << "? 2 3\n";
	cout.flush();
	cin >> b;
	cout << "? 4 5\n";
	cout.flush();
	cin >> c;
	cout << "? 5 6\n";
	cout.flush();
	cin >> d;
	vi v = {4, 8, 15, 16, 23, 42};
	si S;
	S.ins(4);
	S.ins(8);
	S.ins(15);
	S.ins(16);
	S.ins(23);
	S.ins(42);
	for(int i = 0; i < 6; ++i){
		if(a%v[i] == 0 && b%v[i] == 0 && S.count(a/v[i]) && S.count(b/v[i]) && v[i]*v[i] != a && v[i]*v[i] != b){
			n2 = v[i];
		}
	}
	n1 = a/n2;
	n3 = b/n2;
	for(int i = 0; i < 6; ++i){
		if(c%v[i] == 0 && d%v[i] == 0 && S.count(c/v[i]) && S.count(d/v[i]) && v[i]*v[i] != c && v[i]*v[i] != d){
			n5 = v[i];
		}
	}
	n4 = c/n5;
	n6 = d/n5;
	printf("! %d %d %d %d %d %d", n1, n2, n3, n4, n5, n6);
	cout.flush();
		

}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	bool isT = 0;
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