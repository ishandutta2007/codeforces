#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define foreach(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define pub push_back
#define pob pop_back
#define mak make_pair
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

int n, m, k;

void solve() {
    scanf("%d%d%d", &n, &m, &k);
    puts(n * m - 1 == k ? "yes" : "no");
}

int main() {
    int T; scanf("%d", &T);
    while(T--) solve();
    return 0;
}