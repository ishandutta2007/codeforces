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

int n;
int a[5005], b[5005];
ll ans = 0;

int main() {
    scanf("%d", &n);
    cont(i, n) scanf("%d", a + i);
    cont(i, n) scanf("%d", b + i);
    ll dj = 0;
    cont(i, n) dj += 1ll * a[i] * b[i];
    cont(i, n) {
        ll ndj = dj;
        cont(j, n) {
            int l = i - j + 1, r = i + j;
            if (l < 1 || r > n) break;
            ndj -= 1ll * a[l] * b[l] + 1ll * a[r] * b[r];
            ndj += 1ll * a[l] * b[r] + 1ll * a[r] * b[l];
            ans = max(ans, ndj);
        }
        ndj = dj;
        loop(j, n) {
            int l = i - j, r = i + j;
            if (l < 1 || r > n) break;
            ndj -= 1ll * a[l] * b[l] + 1ll * a[r] * b[r];
            ndj += 1ll * a[l] * b[r] + 1ll * a[r] * b[l];
            ans = max(ans, ndj);
        }
    }
    printf("%lld\n", ans);
    return 0;
}