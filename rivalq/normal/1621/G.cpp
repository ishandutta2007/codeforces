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


template<typename T>
struct Fenwick{
    vector<T> tree;
    Fenwick(int n){
        tree.resize(n);
    }

    T query(int i){
        T sum=0;
        while(i){
           sum+=tree[i];
           i-=i&(-i);
       }  
       return sum;
    }
    void update(int i,int n,T val){
       while(i<=n){
          tree[i]+=val;
          i+=i&(-i);
       }
    }
};


int solve(){
 		int n; cin >> n;
 		vector<int> a(n + 1);
 		vector<int> temp;
 		map<int,int> mp;
 		for(int i = 1; i <= n; i++){
 			cin >> a[i];
 			temp.push_back(a[i]);
 		}
 		sort(all(temp));
 		int key = 1;
 		mp[temp[0]] = 1;
 		for(int i = 1; i < n; i++){
 			if(temp[i] != temp[i - 1])key++;
 			mp[temp[i]] = key;
 		}
 		for(int i = 1; i <= n; i++)a[i] = mp[a[i]];
 		Fenwick<mod_int> fn1(n + 1),fn2(n + 1),fn3(n + 1);
 		vector<mod_int>dp(n + 1);
                vector<int> last(n + 1,-1);
 		mod_int ans = 0;
 		for(int i = 1; i <= n; i++){
 			dp[i] = fn1.query(a[i] - 1) + 1;
 			fn1.update(a[i],n,dp[i]);
 		}
 		vector<pii> suff;
                for(int i = n; i >= 1; i--){
                        if(suff.empty() or suff.back().x < a[i]){
                                suff.push_back({a[i],i});
                        }
                        auto j = upper_bound(all(suff),make_pair(a[i],n + 1));
                        if(j != suff.end()){
                                last[i] = j->y;
                        }
                }
                for(int i = n; i >= 1; i--){
                        mod_int val = fn2.query(n) - fn2.query(a[i]) + 1;
                        if(last[i] != -1){
                                ans += val*dp[i];
                        }
                        fn2.update(a[i],n,val);
                }
                vector<vector<int>> vec(n + 1);
                for(int i = 1; i <= n; i++){
                        if(last[i] > 0){        
                                vec[last[i]].push_back(i);
                        }
                }
                for(int i = 1; i <= n; i++){
                        reverse(all(vec[i]));
                        fn3.update(a[i],n,mod_int(1));
                        vector<pair<int,mod_int>>cache;
                        for(auto j:vec[i]){
                                mod_int val = fn3.query(n) - fn3.query(a[j]);
                                ans -= dp[j]*val;
                                fn3.update(a[j],n,val);
                                cache.push_back({a[j],-val});
                        }
                        for(auto i:cache){
                                fn3.update(i.x,n,i.y);
                        }
                        fn3.update(a[i],n,mod_int(-1));
                }
                cout << ans << endl;
 		


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