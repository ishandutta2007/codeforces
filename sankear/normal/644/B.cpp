#pragma comment(linker, "/STACK:256000000")

#include <iostream>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#undef NDEBUG
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pbk pop_back
#define sz(s) ((int) (s).size())
#define len(s) sz(s)
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define prev huprev
#define next hunext
#define link hulink
#define hash huhash
#define rank hurank
#define y0 yy0
#define y1 yy1

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef long double ldouble;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(2e5) + 100;

int d[N];
ll ans[N];
queue<int> q;
set<pair<ll, int> > events;

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, b;
    cin >> n >> b;
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d %d", &t, d + i);
        events.insert(mp(t, i));
    }
    bool available = true;
    while (sz(events) > 0) {
        pair<ll, int> e = *(events.begin());
        events.erase(events.begin());
        if (e.sc == -1) {
            if (!q.empty()) {
                int query = q.front();
                q.pop();
                ll next_time = e.fs + d[query];
                ans[query] = next_time;
                events.insert(mp(next_time, -1));
            } else {
                available = true;
            }
        } else {
            if (available && q.empty()) {
                ll next_time = e.fs + d[e.sc];
                ans[e.sc] = next_time;
                events.insert(mp(next_time, -1));
                available = false;
            } else {
                assert(!available);
                if (sz(q) < b) {
                    q.push(e.sc);
                } else {
                    ans[e.sc] = -1;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf(LLD " ", ans[i]);
    }
    puts("");
    return 0;
}