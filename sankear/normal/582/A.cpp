#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <complex>

#define pb push_back
#define pbk pop_back
#define sz(a) ((int) (a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second
#define next _next
#define prev _prev
#define link _link
#define hash _hash

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

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = 555;

int a[N];
multiset<int> s;

inline int gcd(int a, int b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n * n; ++i) {
        int cur;
        scanf("%d", &cur);
        s.insert(cur);
    }
    for (int i = 0; i < n; ++i) {
        auto it = s.end();
        --it;
        a[i] = *it;
        s.erase(it);
        for (int j = 0; j < i; ++j) {
            for (int z = 0; z < 2; ++z) {
                s.erase(s.find(gcd(a[i], a[j])));
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    puts("");
    return 0;
}