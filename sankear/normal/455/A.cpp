#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define fs first
#define sc second
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef complex<double> tc;
typedef long double ld;

const int inf = int(1e9);
const double pi = 4 * atan(double(1.0));
const double eps = 1e-9;
const int MAX_A = int(1e5);

int a[MAX_A + 100];
ll d[MAX_A + 100][2];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int cur;
        scanf("%d", &cur);
        ++a[cur];
    }
    for (int i = 1; i <= MAX_A; ++i) {
        d[i][0] = max(d[i - 1][0], d[i - 1][1]);
        d[i][1] = d[i - 1][0] + 1LL * a[i] * i;
    }
    cout << max(d[MAX_A][0], d[MAX_A][1]) << endl;
    return 0;
}