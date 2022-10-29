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
			
const int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
// const int dx[8] = {0,1,1,1,0,-1,-1,-1}, dy[8] = {1,1,0,-1,-1,-1,0,1};
const int MOD = 1e9+7; // 998244353;
const int MX = 2e3+5; 
const ll INF = 1e18;

//tree<int,null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> T;

void solve(){
	int n; cin >> n;
	int x, y; cin >> x >> y;
	int x1, y1;
	vector<int> d1(n), d2(n);
	for(int i = n-1; i >= 3; --i){
		cout << "+ " << i << endl;
		cin >> x1 >> y1;
		d1[i] = x1-x, d2[i] = y1-y;
		x = x1, y = y1;
	}
	cout << "+ 1" << endl;
	cin >> x1 >> y1;
	d1[2] = x1-x, d2[2] = y1-y;
	x = x1, y = y1;
	cout << "+ 2" << endl;
	cin >> x1 >> y1;
	d1[1] = x1-x, d2[1] = y1-y;
	x = x1, y = y1;
	cout << "+ 1" << endl;
	cin >> x1 >> y1;
	d1[0] = x1-x, d2[0] = y1-y;
	x = x1, y = y1;
	vector<int> ou(n);
	ou[0] = sqrt(d1[0]*2);
	ou[2] = d2[0]-d2[2]-1;
	ou[1] = d2[2]/(ou[2]+1);
	ou[3] = d2[1]/(ou[2]+1)-ou[0]-2;
	for(int i = 4; i < n; ++i){
		ou[i] = (d2[i-1]-ou[i-4]*ou[i-3])/(ou[i-1]+1)-ou[i-3]-1;
	}
	ou.back()++;
	print('!',ou);
	cout << endl;
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