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



void print(int n,int m,vector<int> vertical){

	vector<vector<char>>color(n+1,vector<char>(m+1,'0'));

	vector<int> dx = {1,-1,0,0};
	vector<int> dy = {0,0,1,-1};
	auto collect = [&](int i,int j){
		set<char>st;
		for(int k = 0; k < 4; k++){
			int x = dx[k] + i;
			int y = dy[k] + j;
			if(x < 1 or y < 1)continue;
			if(x > n or y > m)continue;
			st.insert(color[x][y]);
		}
		return st;
	};		

	auto it = [&](int i,int j, bool down){
		if(color[i][j] != '0')return;
		set<char>st;
		for(int i = 0 ; i < 26; i++){
			st.insert('a' + i);
		}
		if(down){
			auto temp = collect(i,j);
			for(auto i:temp)st.erase(i);
			temp = collect(i + 1,j);
			for(auto i:temp)st.erase(i);
			auto c = *st.begin();
			color[i][j] = color[i + 1][j] = c;
		}else{
			auto temp = collect(i,j);
			for(auto i:temp)st.erase(i);
			temp = collect(i,j + 1);
			for(auto i:temp)st.erase(i);
			auto c = *st.begin();
			color[i][j] = color[i][j + 1] = c;
		}
		
	};
	
	for(int i = 1; i <= m; i++){
		int cur = 1;
		for(int j = 1; j <= vertical[i]; j++){
			it(cur,i,1);
			cur += 2;
		}
		for(cur; cur <= n;cur++)it(cur,i,0);
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << color[i][j];
		}
		cout << endl;
	}

}


int solve(){
 		int n,m,k; cin >> n >> m >> k;
 		vector<int>vertical(m + 1);

 		if(n == 1){
 			if(2*k != n*m){
 				cout << "NO" << endl;
 			}else{
 				cout << "YES" << endl;
 				print(n,m,vertical);
 			}
 			return 0;
 		}
 		if(m == 1){
 			if(k != 0){
 				cout << "NO" << endl;
 			}else{
 				cout << "YES" << endl;
 				vertical[1] = n/2;
 				print(n,m,vertical);
 			}
 			return 0;
 		}
 		int nn = n;
 		int mm = m;
 		k = n*m/2 - k;
 		int cur = 1;
 		if(m%2){
 			k -= n/2;
 			m--;
 			vertical[cur++] = n/2;
 			if(k < 0){
 				cout << "NO" << endl;
 				return 0;
 			}
 		}
 		m /= 2;
 		if(k%2){
 			cout << "NO" << endl;
 			return 0;
 		}
 		bool f = 0;
 		for(int i = 1; i <= m; i++){
 			// N*2
 			if(n%2 == 0){
 				if(k > n){
 					k -= n;
 					vertical[cur++] = n/2;
 					vertical[cur++] = n/2;
 				}
 				else{
 					cout << "YES" << endl;
 					f = 1;
 					vertical[cur++] = k/2;
 					vertical[cur++] = k/2;
 					break;
 				}
 			}else{
 				n--;
 				if(k > n){
 					k -= n;
 					vertical[cur++] = n/2;
 					vertical[cur++] = n/2;	
 				}
 				else{
 					cout << "YES" << endl;
 					f = 1;
 					vertical[cur++] = k/2;
 					vertical[cur++] = k/2;
 					break;
 				}
 			}

 		}
 		if(!f){
 			cout << "NO" << endl;
 			return 0;	
 		}
 			
 		print(nn,mm,vertical);
 		

 		
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