#include <bits/stdc++.h>
#define forn(i,n) for (int i = 0; i < (n); ++i)
#define forab(i,a,b) for (int i = (a); i < (b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define X first
#define Y second
#define db(x) cout << #x << " = " << x << '\n'

#ifdef LOCAL
    #define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
    #define eprintf(args...) ;
#endif

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ipair;
typedef pair<ll, ll> lpair;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-9;

const int N = 100179;

string s;

bool read() {
    if (!(cin >> s)) {
        return 0;
    }
    return 1;
}

int solve() {
    int n = sz(s);
    s += s;
    int L = 0;
    int ans = 0;
    for (int i = 1; i <= sz(s); i++) {
        if (i == sz(s) || s[i] == s[i - 1]) {
            ans = max(ans, min(n, i - L));
            L = i;
        }
    }
    return ans;
}

int main() {
#ifdef LOCAL
    assert(freopen("A.in", "r", stdin));
#endif

    while (read()) {
        cout << solve() << '\n';
    }

    return 0;
}