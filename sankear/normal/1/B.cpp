#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pbk pop_back
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif
#define LLD "%I64d"

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e6);

int ptr;
string cur = "";
char buf[1111];
string ans1[N + 10];
pair<string, int> ans2[N + 10];

void gen(int x, int y) {
    if (x >= y) {
        if (ptr >= N) {
            return;
        }
        ans2[ptr] = mp(cur, ptr + 1);
        ans1[++ptr] = cur;
        return;
    }
    for (int i = 0; i < 26; ++i) {
        cur.pb('A' + i);
        gen(x + 1, y);
        cur.pbk();
    }
}

inline void init() {
    ptr = 0;
    int len = 1;
    while (ptr < N) {
        gen(0, len++);
    }
    sort(ans2, ans2 + N);
}

inline void solve() {
    scanf("%s", buf);
    string s(buf);
    int ptr = 0;
    while (ptr < sz(s) && s[ptr] >= 'A' && s[ptr] <= 'Z') {
        ++ptr;
    }
    for (int i = ptr; i < sz(s); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            assert(ptr == 1);
            int row = 0;
            for (int j = ptr; j < i; ++j) {
                row = row * 10 + s[j] - '0';
            }
            int col = 0;
            for (int j = i + 1; j < sz(s); ++j) {
                col = col * 10 + s[j] - '0';
            }
            printf("%s%d\n", ans1[col].c_str(), row);
            return;
        }
    }
    int row = 0;
    for (int i = ptr; i < sz(s); ++i) {
        row = row * 10 + s[i] - '0';
    }
    int pos = (int) (lower_bound(ans2, ans2 + N, mp(s.substr(0, ptr), -1)) - ans2);
    printf("R%dC%d\n", row, ans2[pos].sc);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    init();
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}