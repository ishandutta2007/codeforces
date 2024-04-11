#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <deque>
#include <queue>
#include <string>
#include <tuple>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>

#define pb push_back
#define pbk pop_back
#define sz(a) ((int) (a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define mt make_tuple
#define fs first
#define sc second
#define next hunext
#define prev huprev
#define rank hurank
#define hash huhash

#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9);
const ll linf = ll(1e18);
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(1e5) + 100;

int cnt[N * 20];
int next[N * 20][2];

int main() {
    cerr << (sizeof(next) + sizeof(cnt)) / 1024 / 1024 << endl;
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    next[0][0] = next[0][1] = -1;
    int sz = 1;
    for (int i = 0; i < n; ++i) {
        char ch;
        scanf(" %c", &ch);
        if (ch == '+' || ch == '-') {
            ll x;
            scanf("%lld", &x);
            vi v;
            if (x == 0) {
                v.pb(0);
            } else {
                while (x > 0) {
                    v.pb((x % 10) % 2);
                    x /= 10;
                }
            }
            while (sz(v) < 18) {
                v.pb(0);
            }
            assert(sz(v) == 18);
            int cur = 0;
            for (int j = 0; j < sz(v); ++j) {
                if (next[cur][v[j]] == -1) {
                    next[sz][0] = next[sz][1] = -1;
                    next[cur][v[j]] = sz++;
                }
                cur = next[cur][v[j]];
            }
            if (ch == '+') {
                ++cnt[cur];
            } else {
                --cnt[cur];
            }
            assert(cnt[cur] >= 0);
        } else {
            assert(ch == '?');
            static char buf[111];
            scanf("%s", buf);
            vi v;
            int len = strlen(buf);
            reverse(buf, buf + len);
            for (int j = 0; j < len; ++j) {
                v.pb(buf[j] - '0');
            }
            while (sz(v) < 18) {
                v.pb(0);
            }
            assert(sz(v) == 18);
            int cur = 0;
            for (int j = 0; j < sz(v) && cur != -1; ++j) {
                cur = next[cur][v[j]];
            }
            if (cur == -1) {
                puts("0");
            } else {
                printf("%d\n", cnt[cur]);
            }
        }
    }
    return 0;
}