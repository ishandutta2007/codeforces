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
const int MX = 1e6+5; 
const ll INF = 1e18;

//tree<int,null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> T;

struct seg{

	seg(int sz) : n(sz), st(4*n), lazy(4*n) {}
	seg(vector<ll> &ini) : seg((int)ini.size()){
		A = ini;
		build(0,n-1,1);
	}

	int n;
	vector<ll> st, lazy, A;

	void mer(int l, int r, int p){
		st[p] = min(st[l],st[r]);
	}

	void build(int l, int r, int p){
		if(l == r){
			st[p] = A[l];
			return;
		}
		int m = (l+r)>>1;
		build(l,m,p*2);
		build(m+1,r,p*2+1);
		mer(p*2,p*2+1,p);
	}

	void prop(int l, int r, int p){
		if(l == r){
			A[l]+=lazy[p];
		}
		else{
			lazy[p*2]+=lazy[p];
			lazy[p*2+1]+=lazy[p];
		}
		st[p]+=lazy[p];
		lazy[p] = 0;
	}

	void update(int l, int r, int p, int lb, int rb, int val){
		prop(l,r,p);
		if(l > rb || r < lb)return;
		if(l >= lb && r <= rb){
			lazy[p]+=val;
			prop(l,r,p);
		}
		else{
			int m = (l+r)>>1;
			update(l,m,p*2,lb,rb,val);
			update(m+1,r,p*2+1,lb,rb,val);
			mer(p*2,p*2+1,p);
		}
	}

	ll que(int l, int r, int p, int lb, int rb){
		prop(l,r,p);
		if(l > rb || r < lb)return INF;
		if(l >= lb && r <= rb){
			return st[p];
		}
		int m = (l+r)>>1;
		return min(que(l,m,p*2,lb,rb),que(m+1,r,p*2+1,lb,rb));
	}
};

void solve(){
	int n; cin >> n;
	vector<ll> v(n); read(v);
	seg st(v);
	int m; cin >> m;cin.ignore();
	for(int i = 0; i < m; ++i){
		string s; getline(cin,s);
		vector<ll> in;
		string cu;
		for(char c : s){
			if(c != ' ')cu+=c;
			else {in.push_back(stoll(cu));cu = "";}
		}
		in.push_back(stoll(cu));
		if(in.size() == 3){
			if(in[0] > in[1]){
				st.update(0,n-1,1,0,in[1],in[2]);
				st.update(0,n-1,1,in[0],n-1,in[2]);
			}
			else{
				st.update(0,n-1,1,in[0],in[1],in[2]);
			}
		}
		else{
			if(in[0] > in[1]){
				cout << min(st.que(0,n-1,1,0,in[1]),st.que(0,n-1,1,in[0],n-1)) << '\n';
			}
			else{
				cout << st.que(0,n-1,1,in[0],in[1]) << '\n';
			}
		}
	}

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