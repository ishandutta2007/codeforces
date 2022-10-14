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

const int maxn=2000005;
int p[maxn];
int sz[maxn];
void clear(int n){
    rep(i,0,n)p[i]=i,sz[i]=1;
}
int root(int x){
   while(x!=p[x]){
       p[x]=p[p[x]];
       x=p[x];
   }
   return x;  
}
void merge(int x,int y){
    int p1=root(x);
    int p2=root(y);
    if(p1==p2)return;
    if(p1 < p2){
        p[p2]=p1;
        sz[p1]+=sz[p2];
    }
    else{
        p[p1]=p2;
        sz[p2]+=sz[p1];
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

#define SIEVE

const int N = 1000050;

int lp[N+1];
int pr[N];int t=0;

void sieve(){
    for (int i=2; i<N; ++i) {
            if (lp[i] == 0) {
                lp[i] = i;
                pr[t++]=i;
            }
        for (int j=0; j<t && pr[j]<=lp[i] && i*pr[j]<N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}


int solve(){
 		int n,k; cin >> n >> k;
                vector<mod_int> pw(n + 1,1),pre(n + 1,1);
                mod_int ans = 0;
                vector<int> mobius(n + 1),mobsum(n + 1);
                mobius[1] = 1;
                for(int i = 2; i <= n; i++){
                        
                        int j = i/lp[i];
                        if(lp[j] == lp[i])mobius[i] = 0;
                        else{
                                mobius[i] = -mobius[j];
                        }
                }
                
                for(int i = 1; i <= n; i++){
                        pw[i] = pw[i - 1]*k;
                        pre[i] = pre[i - 1] + pw[i];
                }

                auto sum = [&](int r,int l){
                        return (l + r)*(r - l + 1)/2;
                };

                auto count = [&](int r,int k){
                        // i + j < k, 1<= i,j <= r, i != j
                        int ans = 0;

                        if(2*r < k){
                                return r*r - r;
                        }

                        
                        if(k >= r + 1){
                                ans = sum(r - 1, k - r - 1) + r*(k - r - 1);
                        }else{
                                ans = sum(k - 2,1);
                        }

                        int val = k/2;
                        if(k % 2 == 0)val--;
                        ans -= val;
                        return ans;
                };   
                int s = 0;   
                for(int d = 1; d < n; d++){
                        ans += pw[n - d];
                        for(int p = 1; p*d < n; p++){
                                int r = (n - 1)/(p*d);
                                int k = (n + d)/(p*d);
                                if((n + d) % (p*d))k++;
                                ans += mobius[p]*count(r,k)*pw[d];
                                s += max(0LL,2*r - k);
                                for(int su = 2*r; su >= k; su--){
                                        // find i,j <= r, i + j == sum
                                        // min(i) -> sum - r
                                        //sum - r, r
                                        //r, 2*r - sum
                                        int val = 0;
                                        if(su % 2 == 0)val++;
                                        ans += mobius[p]*pw[su*p*d - n]*(2*r - su + 1 - val);
                                }
                                /*for(int r1 = 1; r1 <= r; r1++){
                                        for(int r2 = 1; r2 <= r; r2++){
                                                if(r1 == r2)continue;
                                                if((r1 + r2) >= k) {
                                                        int val = (r1 + r2)*p*d - n;
                                                        ans += mobius[p]*pw[(r1 + r2)*p*d - n];
                                                        //cout << (r1 + r2)*p*d - n << endl;
                                                }
                                        }
                                }*/
                        }
                }       
                cout << ans/pw[n] << endl;




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