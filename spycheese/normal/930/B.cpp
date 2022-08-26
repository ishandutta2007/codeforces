#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define ALL(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

// ========================================================================= //

const int N = 100179;

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = sz(s);

    int ans = 0;
    for (int c = 'a'; c <= 'z'; ++c) {
        vector<int> pos;
        for (int i = 0; i < n; ++i)
            if (s[i] == c)
                pos.push_back(i);
        int cans = 0;
        for (int j = 1; j < n; ++j) {
            int cnt[26];
            memset(cnt, 0, sizeof(cnt));
            for (int x : pos) {
                int y = x + j;
                if (y >= n)
                    y -= n;
                cnt[s[y] - 'a']++;
            }
            int c1 = 0;
            for (int j = 0; j < 26; ++j)
                if (cnt[j] == 1)
                    ++c1;
            cans = max(cans, c1);
        }
        ans += cans;
    }

    printf("%.10f\n", (double)ans / n);

    return 0;
}