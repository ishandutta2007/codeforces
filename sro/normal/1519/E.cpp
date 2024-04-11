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

int n, ids;
map<pair<ll, ll>, int> id;
vector<pair<int, int> > nei[400005];

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int getid(ll a, ll b) {
    ll g = gcd(a, b);
    a /= g; b /= g;
    if (!id.count(mak(a, b))) id[mak(a, b)] = ++ids;
    return id[mak(a, b)];
}

bool lgl[400005];
int dep[400005];
vector<pair<int, int> > ans;

bool dfs(int now, int lst, int dne = -1) {
    dep[now] = dep[lst] + 1;
    lgl[now] = 1;
    int tbc = -1;
    parse(it, nei[now]) {
        int to = it.first, id = it.second;
        if (id == dne) continue;
        if (!lgl[to]) {
            if (dfs(to, now, id)) {
                if (~tbc) ans.emb(id, tbc), tbc = -1;
                else tbc = id;
            }
        } else {
            if (dep[to] < dep[now]) {
                if (~tbc) ans.emb(id, tbc), tbc = -1;
                else tbc = id;
            }
        }
    }
    if (~tbc && ~dne) return ans.emb(tbc, dne), 0;
    else return 1;
}

int main() {
    scanf("%d", &n);
    cont(i, n) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int x1 = getid(1ll * (a + b) * d, 1ll * b * c);
        int x2 = getid(1ll * a * d, 1ll * (c + d) * b);
        nei[x1].emb(x2, i); nei[x2].emb(x1, i);
    }
    cont(i, ids) if (!lgl[i]) dfs(i, 0);
    printf("%d\n", SZ(ans));
    parse(it, ans) printf("%d %d\n", it.first, it.second);
    return 0;
}