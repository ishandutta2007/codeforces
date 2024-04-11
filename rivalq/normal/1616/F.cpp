// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


const int MOD = 3;
 
struct mod_int {
    int val;
 
    mod_int(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
 
        if (v >= MOD)
            v %= MOD;
 
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
 
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
 
        return x < 0 ? x + m : x;
    }
 
    explicit operator int() const {
        return val;
    }
 
    mod_int& operator+=(const mod_int &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
 
    mod_int& operator-=(const mod_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
 
    mod_int& operator*=(const mod_int &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
 
    mod_int& operator/=(const mod_int &other) {
        return *this *= other.inv();
    }
 
    friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
    friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
    friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
    friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; }
 
    mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
 
    mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
 
    mod_int operator++(int32_t) { mod_int before = *this; ++*this; return before; }
    mod_int operator--(int32_t) { mod_int before = *this; --*this; return before; }
 
    mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
 
    bool operator==(const mod_int &other) const { return val == other.val; }
    bool operator!=(const mod_int &other) const { return val != other.val; }
 
    mod_int inv() const {
        return mod_inv(val);
    }
 
    mod_int pow(long long p) const {
        assert(p >= 0);
        mod_int a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
 
        return result;
    }
 
    friend ostream& operator<<(ostream &stream, const mod_int &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, mod_int &m) {
        return stream>>m.val;   
    }
};



template<typename T>
int gauss (vector < vector<T> > a, vector<T> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i){
           	if ((a[i][col].val) > (a[sel][col].val))sel = i;
        }
        if ((a[sel][col]) == 0)continue; 
        for (int i=col; i<=m; ++i){
            swap (a[sel][i], a[row][i]);
        }
        where[col] = row;

        for (int i=0; i<n; ++i){
            if (i != row) {
                T c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j){
                    a[i][j] -= a[row][j] * c;
                }
            }
        }    
        ++row;
    }
    for (int i=0; i<m; ++i){
        if (where[i] != -1)ans[i] = a[where[i]][m] / a[where[i]][i];
    }
    for (int i=0; i<n; ++i) {
        T sum = 0;
        for (int j=0; j<m; ++j)sum += ans[j] * a[i][j];
        if ((sum - a[i][m]) != mod_int(0))return 0;
    }

    for (int i=0; i<m; ++i){
        if (where[i] == -1)return 2;
    }    
    return 1;
}



int solve(){
 		int n,m; cin >> n >> m;
 		vector<vector<int>>g(n + 1,vector<int>(n + 1));
 		map<pii,int> mp;
 		vector<vector<mod_int>>cond;

 		for(int i = 1; i <= m; i++){
 			int a,b,c; cin >> a >> b >> c;
 			g[a][b] = c;
 			g[b][a] = c;
 			mp[{min(a,b),max(a,b)}] = i - 1;
 			if(c != -1){
 				vector<mod_int> vec(m + 1);
 				vec[i - 1] = 1;
 				vec[m] = c % 3;
 				cond.push_back(vec);
 			}
 		}



 		for(int i = 1; i <= n; i++){
 			for(int j = i + 1; j <= n; j++){
 				for(int k = j + 1; k <= n; k++){
 					set<int> st;
 					if(g[i][j] > 0 and g[j][k] > 0 and g[i][k] > 0){
 						st.insert(g[i][j]);
 						st.insert(g[i][k]);
 						st.insert(g[j][k]);
 						if(st.size() == 2){
 							cout << -1 << endl;
 							return 0;
 						}
 					}
 					if(g[i][j] != 0 and g[j][k] != 0 and g[i][k] != 0){
 						int id1 = mp[{i,j}];
 						int id2 = mp[{j,k}];
 						int id3 = mp[{i,k}];
 						vector<mod_int> vec(m + 1);
 						vec[id1] = vec[id2] = vec[id3] = 1;
 						cond.push_back(vec);
 					}

 				}
 			}
 		}
 		if(sz(cond) == 0){
 			for(int i = 0; i < m; i++)cout << 3 << " ";cout << endl;
 			return 0;
 		}
 		vector<mod_int> ans(m);
 		auto f = gauss(cond,ans);
 		if(f == 0){
 			cout << -1 << endl;
 			return 0;
 		}else{
 			for(auto i:ans){
 				int x = i.val;
 				if(x == 0)x = 3;
 				cout << x << " ";
 			}
 			cout << endl;
 		}


 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}