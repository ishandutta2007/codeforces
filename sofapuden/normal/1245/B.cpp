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
	int n; cin >> n;
	int R, P, S; cin >> R >> P >> S;
	str s; cin >> s;
	str out;
	int ans = 0;
	for(char c : s){
		if(c == 'R'){
			if(P){
				P--;
				ans++;
				out+="P";
			}
			else{
				out+="J";
			}
		}
		else if(c == 'S'){
			if(R){
				R--;
				ans++;
				out+="R";
			}
			else{
				out+="J";
			}
		}
		else{
			if(S){
				S--;
				ans++;
				out+="S";
			}
			else{
				out+="J";
			}
		}
	}
	if(ans >= cdiv(n,2)){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
		return;
	}
	for(char c : out){
		if(c == 'J'){
			if(R){
				cout << 'R';
				R--;
			}
			else if(P){
				cout << 'P';
				P--;
			}
			else{
				cout << 'S';
				S--;
			}
		}
		else{
			cout << c;
		}
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