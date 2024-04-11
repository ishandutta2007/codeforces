#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;

int uf[500005];
long long c[500005];

#define MOD 1000000007
#define mul(a, b) (((long long)(a) * (long long)(b)) % MOD)

int fpow(int base, int exponent)
{
    int ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1) ans = mul(ans, cur);
        cur = mul(cur, cur); exponent >>= 1;
    }
    return ans;
}

long long read(void)
{
    long long a;
#ifdef ONLINE_JUDGE
    scanf("%I64d", &a);
#else
    scanf("%lld", &a);
#endif
    return a;
}

struct Edge {
    int from, to; long long val;
};

vector<Edge> all_edges;

bool operator<(Edge a, Edge b)
{
    return a.val < b.val;
}

int find(int a)
{
    //fprintf(stderr, "Find %d\n", a);
    if (uf[a] == a) return a;
    return uf[a] = find(uf[a]);
}

void un(int a, int b)
{
    a = find(a);
    b = find(b);
    uf[a] = b;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) uf[i] = i;
    for (int i = 1; i <= n; i++) c[i] = read();
    for (int i = 1; i <= m; i++) {
        Edge e;
        scanf("%d%d", &e.from, &e.to);
        e.val = c[e.from] ^ c[e.to];
        all_edges.push_back(e);
    }
    sort(all_edges.begin(), all_edges.end());
    int cur = 0;
    int ans = 0;
    int dist_vals = 0;
    while (cur < m) {
        int setcnt = n;
        vector<int> changed;
        do {
            Edge e = all_edges[cur];
            //for (int i = 1; i <= n; i++) fprintf(stderr, "%d ", uf[i]);
            //fprintf(stderr, "\n");
            //fprintf(stderr, "%d [%d %d]", cur, e.from, e.to);
            if (find(e.from) != find(e.to)) {
                changed.push_back(e.from);
                changed.push_back(e.to);
                setcnt--; un(e.from, e.to);
            }
            cur++;
            //fprintf(stderr, "end %d\n", cur);
        } while (cur < m && all_edges[cur].val == all_edges[cur-1].val);
        //fprintf(stderr, "end %d\n", setcnt);
        ans += fpow(2, setcnt);
        if (ans >= MOD) ans -= MOD;
        //fprintf(stderr, "end2\n");
        for (int i = 0; i < changed.size(); i++) uf[changed[i]] = changed[i];
        //for (int i = 1; i <= n; i++) fprintf(stderr, "%d ", uf[i]);
        //fprintf(stderr, "\n");
        dist_vals++;
        //fprintf(stderr, "%d ", cur);
    }
    //printf("dist_vals: %d\n", dist_vals);
    ans += mul(fpow(2, n), (fpow(2, k) - dist_vals + MOD) % MOD);
    if (ans >= MOD) ans -= MOD;
    printf("%d", ans);
    return 0;
}