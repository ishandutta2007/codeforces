#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <bitset>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#define pbk pop_back
#define prev _prev
#define rank _rank
#define next _next
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

typedef long long ll;
typedef long long int64;
typedef unsigned long long ull;
typedef unsigned long long lint;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;

const double inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(2e5) + 100;

char a[N], b[N];

inline bool is_less(char *s, int p1, int p2, int len) {
    int ptr = 0;
    while (ptr < len && s[p1 + ptr] == s[p2 + ptr]) {
        ++ptr;
    }
    return ptr < len && s[p1 + ptr] < s[p2 + ptr];
}

void norm(char *s, int l, int r) {
    if ((r - l + 1) % 2 != 0) {
        return;
    }
    int mid = (l + r) / 2;
    norm(s, l, mid);
    norm(s, mid + 1, r);
    if (is_less(s, mid + 1, l, (r - l + 1) / 2)) {
        for (int i = l; i <= mid; ++i) {
            swap(s[i], s[mid + 1 + (i - l)]);
        }
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    gets(a);
    gets(b);
    int n = (int) strlen(a);
    norm(a, 0, n - 1);
    norm(b, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}