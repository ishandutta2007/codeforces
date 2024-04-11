#include <bits/stdc++.h>

#define MOD (1000000007)
#define EPS (1e-9)
#define INF (2117117117)
#define LLINF (2117117117117117117LL)
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define sqr(a) ((a) * (a))
#define sz(a) ((int) (a).size())
const double PI = acos(-1.0);

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef unsigned int uint;
typedef long long llong;
typedef long double ldouble;
typedef unsigned long long ullong;

#define TASK "task"

using namespace std;

const int MAXN = 500117;

struct Tree
{
    int l, r, m;
    Tree *L, *R;
};

int n, m, arr[MAXN], ans[MAXN];
pair<pair<int, int>, int> q[MAXN];
map<int, int> last;
Tree *t;

Tree* build(int l, int r)
{
    Tree *res = new Tree;
    res->l = l;
    res->r = r;
    res->m = INF;
    if (r - l == 1)
    {
        res->L = 0;
        res->R = 0;
    }
    else
    {
        int x = (l + r) >> 1;
        res->L = build(l, x);
        res->R = build(x, r);
    }
    return res;
}

void upd(Tree *T, int i, int d)
{
    if (i < T->l || T->r <= i)
        return;
    if (T->r - T->l == 1)
    {
        T->m = d;
        return;
    }
    upd(T->L, i, d);
    upd(T->R, i, d);
    T->m = min(T->L->m, T->R->m);
}

int get(Tree *T, int l, int r)
{
    if (r <= T->l || T->r <= l)
        return INF;
    if (l <= T->l && T->r <= r)
        return T->m;
    return min(get(T->L, l, r), get(T->R, l, r));
}

int main()
{
#ifdef lordf
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &q[i].first.first, &q[i].first.second);
        q[i].first.first--;
        q[i].second = i;
    }
    sort(q, q + m);

    t = build(0, n);
    for (int i = m - 1, j = n - 1; i >= 0; i--)
    {
        for (; j >= q[i].first.first; j--)
        {
            if (last.count(arr[j]))
                upd(t, last[arr[j]], last[arr[j]] - j);
            last[arr[j]] = j;
        }

        ans[q[i].second] = get(t, j, q[i].first.second);
    }

    for (int i = 0; i < m; i++)
        printf("%d\n", (ans[i] == INF ? -1 : ans[i]));

    return 0;
}