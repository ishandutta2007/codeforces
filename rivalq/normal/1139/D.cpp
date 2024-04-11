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


const int N = 1e5+5;

vector<int>p[N],d[N];



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


mod_int dp[N];


int pie(vector<int> p,int m){
    int ans=0;
    int n=p.size();
    for(int i=1;i<(1L<<n);i++){
        int cnt=0;
        int a=1;
        for(int j=0;j<n;j++){
            int k=1<<j;
            if(i&k)a=a*p[j],cnt++;
        }
        if(cnt&1)ans+=m/a;
        else ans-=m/a;
    }
    return m-ans;
}

int solve(){
 		for(int i = 2; i < N; i++){
 			if(p[i].size() == 0){
 				for(int j = i; j < N; j += i){
 					p[j].push_back(i);
 				}
 			}
 		}

 		for(int i = 1; i < N; i++){
 			for(int j = i; j < N; j += i){
 				d[j].push_back(i);
 			}
 		}

 		// number of integer coprime to some x in [1,y]
 		auto func = [&] (int x,int y) -> int{

 			int ans = 0;
 			int m = p[x].size();
 			for(int i = 1; i < 1<<m; i++){
 				int cnt = 0;
 				int a = 1;
 				for(int j = 0; j < m; j++){
 					if((1<<j) & i){
 						cnt++;
 						a *= p[x][j];
 					}
 				}
 				ans += (cnt%2)?(y/a):(-y/a);
 			}
 			return y - ans;

 		};


 		dp[1] = 0;
 		
 		int m;cin >> m;

 		mod_int t = m;
 		t = t.inv();

 		for(int i = 2; i <= m; i++){
 				mod_int val = 0;
 				for(auto j:d[i]){
 					if(j==i)continue;
 					val += (1+dp[j])*func(i/j,m/j);	
 				}
 				val += (m/i);


 				mod_int x = m - m/i;

 				dp[i] = val/x;

 		}

 		mod_int ans = 0;
 		
 		for(int i = 1; i <= m; i++){
 			ans += (1+dp[i])*t;
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
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}