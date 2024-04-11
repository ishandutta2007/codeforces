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
#include <stack>
#include <queue>
#include <deque>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#define fs first
#define sc second

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5) + 100;

char s[N];
bool used[N];
int st[N];
vi lst;

inline void fail() {
    puts("-1");
    exit(0);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    
#endif
    gets(s);
    int n = (int) strlen(s), k = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '#') {
            ++cnt;
            continue;
        }
        if (s[i] == '(') {
            st[k++] = i;
            continue;
        }
        if (k == 0) {
            fail();
        }
        used[st[--k]] = true;
    }
    int bal = 0;
    for (int i = 0; i < n; ++i) {
        if (used[i]) {
            continue;
        }
        if (s[i] == ')') {
            continue;
        }
        if (s[i] == '(') {
            ++bal;
            continue;
        }
        if (bal == 0) {
            fail();
        }
        if (cnt == 1) {
            lst.pb(bal);
            bal = 0;
        } else {
            lst.pb(1);
            --bal;
        }
        --cnt;
    }
    if (bal > 0) {
        fail();
    }
    for (int i = 0; i < sz(lst); ++i) {
        printf("%d\n", lst[i]);
    }
    return 0;
}