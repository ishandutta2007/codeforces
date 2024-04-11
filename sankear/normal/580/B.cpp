#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <complex>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define pbk pop_back
#define all(x) (x).begin(), (x).end()
#define sz(s) ((int) (s).size())
#define fs first
#define sc second
#define prev _prev
#define next _next
#define rank _rank
#define hash _hash
#define left _left
#define right _right

#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

const int inf = 1e9;
const double pi = 4 * atan(1.0);
const double eps = 1e-9;
const int N = int(1e5) + 100;

pii a[N];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a[i].fs, &a[i].sc);
    }
    sort(a, a + n);
    ll ans = 0, sum = a[0].sc;
    int ptr = 0;
    for (int i = 0; i < n; ++i) {
        if (ptr < i) {
            ptr = i;
            sum = a[i].sc;
        }
        while (ptr + 1 < n && a[ptr + 1].fs < a[i].fs + d) {
            ++ptr;
            sum += a[ptr].sc;
        }
        ans = max(ans, sum);
        sum -= a[i].sc;
    }
    cout << ans << endl;
    return 0;
}