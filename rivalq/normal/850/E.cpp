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


namespace fwht{


	template<typename T>
	void hadamard_xor(vector<T> &a){
		int n = a.size();
		for(int k = 1 ; k < n ; k <<= 1){
			for(int i = 0 ; i < n ; i += 2*k){
				for(int j = 0 ; j < k ; j++){
					T x = a[i + j];
					T y = a[i + j + k];
					a[i + j] = x + y;
					a[i + j + k] = x - y;
				}
			}
		}
	}
	template<typename T>
	void hadamard_or(vector<T> &a,bool inverse){
		int n = a.size();
		for(int k = 1 ; k < n ; k <<= 1){
			for(int i = 0 ; i < n ; i += 2*k){
				for(int j = 0 ; j < k ; j++){
					T x = a[i + j];
					T y = a[i + j + k];
					if(inverse){
						a[i + j] = y - x;
						a[i + j +k] = x;
					}
					else{
						a[i + j] = y;
						a[i + j + k] = x + y;
					}
				}
			}
		}
	}
	template<typename T>
	void hadamard_and(vector<T> &a,bool inverse){
		int n = a.size();
		for(int k = 1 ; k < n ; k <<= 1){
			for(int i = 0 ; i < n ; i += 2*k){
				for(int j = 0 ; j < k ; j++){
					T x = a[i + j];
					T y = a[i + j +k];
					if(inverse){
						a[i + j] = x - y;
						a[i + j + k] = y;
					}
					else{
						a[i + j] = x + y;
						a[i + j + k] = y;	
					}
					
				}
			}
		}
	}
	template<typename T>
	vector<T> multiply(vector<T> a,vector<T> b){
		int eq = (b==a);
		int n = 1 ;
		while (n < (int)max(a.size(),b.size())){
			n <<= 1;
		} 
		a.resize(n);
		b.resize(n);
		hadamard_xor(a);
		if (eq) b = a; else hadamard_xor(b);
		for(int i = 0 ; i < n ; i++){
			a[i]*=b[i];
		}
		hadamard_xor(a);
		T q = static_cast<T>(n);
		for(int i = 0 ; i < n ; i++){
			a[i]/=q;
		}
		return a;
	}


}

const int MOD = hell;
 
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
 		vector<int> a(1 << n),b(1 << n);
 		for(int i = 0; i < (1 << n); i++){
 			char c; cin >> c;
 			if(c == '0')a[i] = 0,b[i] = 1;
 			else a[i] = 1,b[i] = 0;
 		}

 		auto c = fwht::multiply(a,b);
 		mod_int ans = 0;
 		for(int i = 0; i < (1 << n); i++){
 			int p = __builtin_popcount(i);
 			int p2 = n - p;
 			ans += c[i]*mod_int(2).pow(p);
 		}
 		cout << ans*3 << endl;
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