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
	int n, m; cin >> n >> m;
	vs v(n); read(v);
	vt<array<int,6>> out;
	
	if(m&1){
		for(int i = 0; i < n; ++i){
			if(v[i][0] == '1'){
				array<int,6> cur;
				cur[0] = i+1;
				cur[1] = 1;
				v[i][0] = (v[i][0] == '1' ? '0' : '1');
				cur[2] = i+1;
				cur[3] = 2;
				v[i][1] = (v[i][1] == '1' ? '0' : '1');
				if((!i && !(n&1)) || ((n&1) && i<=1)){
					cur[4] = i+2;
					cur[5] = 1;
					v[i+1][0] = (v[i+1][0] == '1' ? '0' : '1');
				}
				else{
					cur[4] = i;
					cur[5] = 2;
					v[i-1][1] = (v[i-1][1] == '1' ? '0' : '1');
				}
				out.pb(cur);
			}
		}
	}
	if(n&1){
		for(int i = 0; i < m; ++i){
			if(v[0][i] == '1'){
				array<int,6> cur;
				cur[0] = 1;
				cur[1] = i+1;
				v[0][i] = (v[0][i] == '1' ? '0' : '1');
				cur[2] = 2;
				cur[3] = i+1;
				v[1][i] = (v[1][i] == '1' ? '0' : '1');
				if((!i && !(m&1)) || ((m&1) && i<=1)){
					cur[4] = 1;
					cur[5] = i+2;
					v[0][i+1] = (v[0][i+1] == '1' ? '0' : '1');
				}
				else{
					cur[4] = 2;
					cur[5] = i;
					v[1][i-1] = (v[1][i-1] == '1' ? '0' : '1');
				}
				out.pb(cur);
			}
		}
	}
	for(int i = n-2; i >= 0; i-=2){
		for(int j = m-2; j >= 0; j-=2){
			while(1){
				array<int,6> cur;
				if(v[i][j]+v[i+1][j]+v[i][j+1]+v[i+1][j+1]-4*'0' == 0){
					break;
				}
				if(v[i][j]+v[i+1][j]+v[i][j+1]+v[i+1][j+1]-4*'0' == 1){
					int cn = 0;
					int cn2 = 0;
					if(v[i][j] == '1'){
						cur[cn++] = i+1;
						cur[cn++] = j+1;
						v[i][j] = (v[i][j] == '1' ? '0' : '1');
					}
					else if(cn2 < 2){
						cur[cn++] = i+1;
						cur[cn++] = j+1;
						cn2++;
						v[i][j] = (v[i][j] == '1' ? '0' : '1');						
					}
					
					if(v[i+1][j] == '1'){
						cur[cn++] = i+2;
						cur[cn++] = j+1;
						v[i+1][j] = (v[i+1][j] == '1' ? '0' : '1');
					}
					else if(cn2 < 2){
						cur[cn++] = i+2;
						cur[cn++] = j+1;
						cn2++;
						v[i+1][j] = (v[i+1][j] == '1' ? '0' : '1');
					}
					
					if(v[i][j+1] == '1'){
						cur[cn++] = i+1;
						cur[cn++] = j+2;
						v[i][j+1] = (v[i][j+1] == '1' ? '0' : '1');
					}
					else if(cn2 < 2){
						cur[cn++] = i+1;
						cur[cn++] = j+2;
						cn2++;
						v[i][j+1] = (v[i][j+1] == '1' ? '0' : '1');
					}
					
					if(v[i+1][j+1] == '1'){
						cur[cn++] = i+2;
						cur[cn++] = j+2;
						v[i+1][j+1] = (v[i+1][j+1] == '1' ? '0' : '1');
					}
					else if(cn2 < 2){
						cur[cn++] = i+2;
						cur[cn++] = j+2;
						cn2++;
						v[i+1][j+1] = (v[i+1][j+1] == '1' ? '0' : '1');
					}
					out.pb(cur);
					continue;
				}
				if(v[i][j]+v[i+1][j]+v[i][j+1]+v[i+1][j+1]-4*'0' == 2){
					int cn = 0;
					int cn2 = 0;
					if(v[i][j] == '0'){
						cur[cn++] = i+1;
						cur[cn++] = j+1;
						v[i][j] = (v[i][j] == '1' ? '0' : '1');
					}
					else if(cn2 < 1){
						cur[cn++] = i+1;
						cur[cn++] = j+1;
						cn2++;
						v[i][j] = (v[i][j] == '1' ? '0' : '1');
					}
					
					if(v[i+1][j] == '0'){
						cur[cn++] = i+2;
						cur[cn++] = j+1;
						v[i+1][j] = (v[i+1][j] == '1' ? '0' : '1');
					}
					else if(cn2 < 1){
						cur[cn++] = i+2;
						cur[cn++] = j+1;
						cn2++;
						v[i+1][j] = (v[i+1][j] == '1' ? '0' : '1');
					}
					
					if(v[i][j+1] == '0'){
						cur[cn++] = i+1;
						cur[cn++] = j+2;
						v[i][j+1] = (v[i][j+1] == '1' ? '0' : '1');
					}
					else if(cn2 < 1){
						cur[cn++] = i+1;
						cur[cn++] = j+2;
						cn2++;
						v[i][j+1] = (v[i][j+1] == '1' ? '0' : '1');
					}
					
					if(v[i+1][j+1] == '0'){
						cur[cn++] = i+2;
						cur[cn++] = j+2;
						v[i+1][j+1] = (v[i+1][j+1] == '1' ? '0' : '1');
					}
					else if(cn2 < 1){
						cur[cn++] = i+2;
						cur[cn++] = j+2;
						cn2++;
						v[i+1][j+1] = (v[i+1][j+1] == '1' ? '0' : '1');
					}
					out.pb(cur);
					continue;
				}
					

				if(v[i][j]+v[i+1][j]+v[i][j+1]+v[i+1][j+1]-4*'0' == 3){
					int cn = 0;
					if(v[i][j] == '1'){
						cur[cn++] = i+1;
						cur[cn++] = j+1;
						v[i][j] = (v[i][j] == '1' ? '0' : '1');
					}
					if(v[i+1][j] == '1'){
						cur[cn++] = i+2;
						cur[cn++] = j+1;
						v[i+1][j] = (v[i+1][j] == '1' ? '0' : '1');
					}
					if(v[i][j+1] == '1'){
						cur[cn++] = i+1;
						cur[cn++] = j+2;
						v[i][j+1] = (v[i][j+1] == '1' ? '0' : '1');
					}
					if(v[i+1][j+1] == '1'){
						cur[cn++] = i+2;
						cur[cn++] = j+2;
						v[i+1][j+1] = (v[i+1][j+1] == '1' ? '0' : '1');
					}
					out.pb(cur);
					continue;
				}
				cur = {i+1,j+1,i+2,j+1,i+1,j+2};
				v[i][j] = (v[i][j] == '1' ? '0' : '1');
				v[i+1][j] = (v[i+1][j] == '1' ? '0' : '1');
				v[i][j+1] = (v[i][j+1] == '1' ? '0' : '1');
				out.pb(cur);
			}
		}
	}
	print(sz(out));
	for(auto i : out){
		print(i[0],i[1],i[2],i[3],i[4],i[5]);
	}
}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	bool isT = 1;
	if(isT){
		int t; cin >> t; while(t--){
			solve();
		}
		return 0;
	}
	solve();		
	return 0;
}