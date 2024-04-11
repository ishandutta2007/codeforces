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
#define NCR
const int N=1e6;
mod_int fact[N],inv[N];
void init(int n=N){
	fact[0]=inv[0]=inv[1]=1;
	rep(i,1,N)fact[i]=i*fact[i-1];
	rep(i,2,N)inv[i]=fact[i].inv();
}
mod_int C(int n,int r){
	if(r>n || r<0)return 0;
	return fact[n]*inv[n-r]*inv[r];
}

int solve(){
 		int n; cin >> n;
 		vector<string> vec(n);
 		int cntbb = 0;
 		int cntb_ = 0;
 		int cnt_b = 0;
 		int cnt__ = 0;
 		int cntww = 0;
 		int cntw_ = 0;
 		int cnt_w = 0;
 		int cntbw = 0;
 		int cntwb = 0;
 		for(auto &i:vec){
 			cin >> i;
 			if(i == "BB")cntbb++;
 			if(i == "B?")cntb_++;
 			if(i == "?B")cnt_b++;
 			if(i == "??")cnt__++;
 			if(i == "WW")cntww++;
 			if(i == "?W")cnt_w++;
 			if(i == "W?")cntw_++;
 			if(i == "BW")cntbw++;
 			if(i == "WB")cntwb++;
 		}

 		int c1 = 0, c2 = 0;
 		mod_int c3 = 0;
 		if(cntbb == 0 and cntww == 0){
 			c3 -= mod_int(2).pow(cnt__);
 			if(cntw_ == 0 and cnt_b == 0 and cntwb == 0)c3++;
 			if(cntb_ == 0 and cnt_w == 0 and cntbw == 0)c3++;
 		}
 		//cout << c3 << endl;
 		int bal = cntbb - cntww - cnt_w - cntw_;
 		int m = cntb_ + cnt_b + cnt_w + cntw_;

 		map<int,mod_int> mp;
 		for(int i = 0; i <= m; i++){
 			mp[bal + i] = C(m,i);
 		}
 		for(auto i:mp){
 			int need = -i.x;
 			c3 += C(2*cnt__,need + cnt__)*i.y;
 		}
 		cout << c3 << endl;

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