#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define Sort(v) sort(v.begin(), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define all(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)
#define bit(n) (1LL<<(n))
#define bit_exist(x, n) ((x >> n) & 1)
#define Ans(f, y, n) if(f) cout << y << endl; else cout << n << endl;
#define debug(x) cout << #x << "=" << x << endl;
#define vdebug(v) cout << #v << "=" << endl; REP(i, v.size()){ cout << v[i] << ","; } cout << endl;
#define mdebug(m) cout << #m << "=" << endl; REP(i, m.size()){ REP(j, m[i].size()){ cout << m[i][j] << ","; } cout << endl;}
#define pb push_back
#define f first
#define s second
#define int long long
#define INF 1000000000000000000

using vec = vector<int>;
using mat = vector<vec>;
using Pii = pair<int, int>;
using PiP = pair<int, Pii>;
using PPi = pair<Pii, int>;
using bools = vector<bool>;
using pairs = vector<Pii>;

template<typename T> void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readv_m1(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }

//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};

int mod = 1000000007;
//int mod = 998244353;
#define Add(x, y) x = (x + (y)) % mod
#define Mult(x, y) x = (x * (y)) % mod

int extgcd(int a, int b, int &x, int &y){
    int d = a;
    if(b != 0){
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }else{
        x = 1;
        y = 0;
    }
    return d;
}

signed main(){

    int m, a, b; cin >> m >> a >> b;
    int x, y;
    int g = extgcd(a, b, x, y);
    //debug(g);

    int now = 0, M = 0;
    vec dp(200001, INF);
    dp[0] = 0;
    while(true){
        /*
        if(now < g && (g - now) % a == 0) now = g;
        else if(g < now && (now - g) % b == 0) now = g;
        else if(now >= b) now %= b;
        else now += ((b - now - 1) / a + 1) * a;
        Max(M, now);
        */
       if(now >= b) now -= b;
       else now += a;
       Max(M, now);
       Min(dp[now], M);
       if(now == 0) break;
    }
    //REP(i, a) if(i % g == 0 && i >= g) Min(dp[i], dp[i - g] + M);  
    //vdebug(dp);
    //debug(M);
    int ans = 0;
    
    for(int i = 0; i < a; i += g){
        int K = dp[i];
        /*
        if(i == 0) K = 0;
        else K = M + i;*/
        if(K > m) continue;

        // ~K
        int n1 = (K - i) / a + 1;
        ans += (m - K + 1) * n1;
        // K+1~
        int n2 = (m - i) / a + 1;
        ans += (m + 1 - i) * (n2 - n1) - a * (n2 * (n2 - 1) / 2 - n1 * (n1 - 1) / 2);
    }
    cout << ans << endl;


    return 0;
}