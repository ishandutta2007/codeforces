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

const int MOD = 998244353;
 
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

int solve(){
 		int n; cin >> n;

 		string s; cin >> s;
 		vector<int>pre(n + 1);
 		for(int i = 1; i <= n; i++){
 			pre[i] = pre[i - 1] + (s[i - 1] == '?');
 		}
 		

 		vector<vector<mod_int>> dp(18,vector<mod_int>(1 << 17));
 		vector<vector<int>>f(n,vector<int>(n));
 		vector<vector<int>>ext(n,vector<int>(n));
 		vector<vector<mod_int>> pows(18,vector<mod_int>(n + 1));
 		for(int i = 1; i <= 17; i++){
 			pows[i][0] = 1;
 			for(int j = 1; j <= n; j++){
 				pows[i][j] = pows[i][j - 1]*i;
 			}

 		}

 		auto sum = [&](int l,int r){
 			return pre[r] - pre[l - 1];
 		};	
 		for(int i = 0; i < n; i++){
 			if(s[i] == '?'){
 				ext[i][i] = 1;
 			}
 			int p = __builtin_popcount(f[i][i]);
			int mask = f[i][i];
			int e = ext[i][i];
			int tot = pre[n] - sum(i + 1,i + 1);
			for(p; p <= 17; p++){
				dp[p][mask] += pows[p][e + tot];
			}
 		}

 		

 		for(int len = 2; len <= n; len++){
 			for(int i = 0,j = len - 1; j < n; i++,j++){
 				if(f[i + 1][j - 1] == -1){
 					f[i][j] = -1;
 					continue;
 				}
 				if(s[i] == s[j]){
 					f[i][j] = f[i + 1][j - 1];
 					ext[i][j] = ext[i + 1][j - 1] + (s[i] == '?');
 				}else{
 					if(s[i] == '?'){
 						int k  = (1 << (s[j] - 97));
 						f[i][j] = (f[i + 1][j - 1] | k);
 						ext[i][j] = ext[i + 1][j - 1]; 
 					}else if(s[j] == '?'){
 						int k = (1 << (s[i] - 97));
 						f[i][j] = (f[i + 1][j - 1] | k);
 						ext[i][j] = ext[i + 1][j - 1];
 					}else{
 						f[i][j] = -1;
 					}
 				}
 				if(f[i][j] == -1){
 					continue;
 				}
 				int p = __builtin_popcount(f[i][j]);
 				int mask = f[i][j];
 				int e = ext[i][j];
 				int tot = pre[n] - sum(i + 1,j + 1);
 				for(p; p <= 17; p++){
 					dp[p][mask] += pows[p][e + tot];
 				}
 			}
 		}

 		for(int p = 0; p <= 17; p++){
 			for(int i = 0; i < 17; i++){
 				for(int mask = 0; mask < (1 << 17); mask++){
 					if((1 << i) & mask){
 						dp[p][mask] += dp[p][mask^(1 << i)];
 					}
 				}
 			}
 		}



 		int q; cin >> q;
 		while(q--){
 			string t; cin >> t;
 			int mask = 0;
 			for(auto i:t){
 				int j = i - 'a';
 				mask |= (1 << j);
 			}
 			int p = __builtin_popcount(mask);
 			cout <<  dp[p][mask] << endl;
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
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}