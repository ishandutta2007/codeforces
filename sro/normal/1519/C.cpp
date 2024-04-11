#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

int n;
int u[200005], s[200005];
ll sm[200005], pre[200005];
vector<int> xs[200005];

void solve() {
    scanf("%d", &n);
    cont(i, n) sm[i] = 0;
    cont(i, n) xs[i].clear();
    cont(i, n) scanf("%d", u + i);
    cont(i, n) scanf("%d", s + i), xs[u[i]].pub(s[i]);
    cont(i, n) {
        sort(all(xs[i]), greater<int>()); int len = SZ(xs[i]);
        loop(j, len) pre[j + 1] = pre[j] + xs[i][j];
        cont(j, len) sm[j] += pre[len / j * j];
    }
    cont(i, n) printf("%lld%c", sm[i], " \n"[i == n]);
}

int main() {
    int T; scanf("%d", &T);
    while(T--) solve();
    return 0;
}