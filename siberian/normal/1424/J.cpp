#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
#include <stack>
#include <deque>
#include <ctime>
#include <random>
#include <cassert>
#include <cmath>
#include <climits>
#include <queue>
#include <cstring>
#include <bitset>
#include <iomanip>
#include <chrono>

/*
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("popcnt")
#pragma GCC target("avx2")
*/


#ifdef LOCAL
    #define dbg(x) cout << #x << " : " << x << endl;
#else
    #define dbg(x)
#endif

#define int long long
#define pb push_back
#define ppb pop_back()
#define mp make_pair
#define fi(a, b) for (int i = a; i < b; i++)
#define fj(a, b) for (int j = a; j < b; j++)
#define fk(a, b) for (int k = a; k < b; k++)
#define fi1(a, b) for (int i = a - 1; i >= b; i--)
#define fj1(a, b) for (int j = a - 1; j >= b; j--)
#define fk1(a, b) for (int k = a - 1; k >= b; k--)
#define fx(x, a) for (auto& x : a)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rep1(i, a, b) for (int i = a - 1; i >= b; --i)
#define siz(x) (int)x.size()
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;

template<typename T1, typename T2>inline void mine(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void maxe(T1 &x, T2 y) { if (x < y) x = y; }

ostream& operator << (ostream &a, const vector<int> &b) {
    for (auto k : b) cout << k << ' ';
    return a;
}


typedef long long ll;
typedef unsigned long long ull;
typedef char ch;
typedef string str;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<ch> vch;
typedef vector<vch> vvch;
typedef vector<str> vs;



const int MOD = 1000000007;
const int INF = 1000000050;
const long long BIG = (long long)2e18 + 50;
const int MX = 1001000;
const double EPS = 1e-9;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int ld[MX];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	vi primes;
    primes.reserve(MX / 10 + 30);
    memset(ld, -1, sizeof(int) * MX);
    fi(2, MX) {
        if (ld[i] == -1) {
            primes.push_back(i);
            ld[i] = i;
        }
        fx(x, primes) {
            if (1ll * x * i >= MX || x > ld[i])
                break;
            ld[i * x] = x;
        }
    }
    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	int ans = ub(all(primes), n) - primes.begin();
    	for (int i = 0; ; ++i) {
    		if (primes[i] * primes[i] <= n) 
    			--ans;
    		else
    			break;
    	}
    	cout << ans + 1 << '\n';
    }
}