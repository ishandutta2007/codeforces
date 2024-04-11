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
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#ifdef LOCAL42
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif
#define next _next
#define prev _prev
#define hash _hash
#define rank _rank
#define link _link

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef complex<double> tc;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const char* buf[] = {
    "vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"
};

char s[100];

inline bool check(const char *s, char *t) {
    int n = strlen(s), m = strlen(t);
    if (n != m) {
        return false;
    }
    for (int i = 0; i < n; ++i) {
        if (t[i] == '.') {
            continue;
        }
        if (s[i] != t[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    scanf("%d %s", &n, s);
    for (int i = 0; i < 8; ++i) {
        if (check(buf[i], s)) {
            puts(buf[i]);
            return 0;
        }
    }
    return 0;
}