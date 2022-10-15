#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

int n, q;

int p[200005], nxt[200005];
ll a[200005], b[200005];

int stk[200005], stktop = 0;
int ptr[200005]; ll ncost[200005];

const int blksize = 700;
int func[200005];
ll fcost[200005];
int nxtblock[200005];
ll nxtcost[200005];

int blkend[200005];

vector<int> qryprev[200005];
vector<int> nxtprev[200005];

void init_func()
{
    for (int i = 1; i <= n; i++) {
        blkend[i] = min(((i - 1) / blksize + 1) * blksize, n);
    }
    blkend[n + 1] = n + 1;
    for (int i = n; i >= 1; i--) {
        if (func[i] > blkend[i]) {
            nxtblock[i] = func[i];
            nxtcost[i] = fcost[i];
        } else {
            nxtblock[i] = nxtblock[func[i]];
            nxtcost[i] = nxtcost[func[i]] + fcost[i];
        }
        //printf("! %d %lld\n", nxtblock[i], nxtcost[i]);
    }
}

ll query_func(int from, int to)
{
    ll ans = 0;
    while (from < to) {
        if (blkend[from] == blkend[to]) {
            ans += fcost[from];
            from = func[from];
        } else {
            ans += nxtcost[from];
            from = nxtblock[from];
        }
        //printf("%d\n", from);
    }
    return ans;
}

void modify_func(int loc, int n_func, ll n_cost)
{
    func[loc] = n_func;
    fcost[loc] = n_cost;
    for (int i = blkend[loc]; blkend[i] == blkend[loc]; i--) {
        if (func[i] > blkend[i]) {
            nxtblock[i] = func[i];
            nxtcost[i] = fcost[i];
        } else {
            nxtblock[i] = nxtblock[func[i]];
            nxtcost[i] = nxtcost[func[i]] + fcost[i];
        }
    }
}

struct Triple {
    int from, to, weight;
};

Triple make_triple(int from, int to, int weight)
{
    Triple t; t.from = from; t.to = to; t.weight = weight;
    return t;
}

vector<Triple> change[200005];

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", p + i);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    for (int i = 1; i <= n; i++) scanf("%lld", b + i);
    p[n + 1] = n + 1;
    stk[stktop++] = n + 1;
    vector<pair<int, int> > intv;
    for (int i = n; i >= 1; i--) {
        while (p[stk[stktop - 1]] < p[i]) stktop--;
        nxt[i] = stk[stktop - 1];
        nxtprev[nxt[i]].push_back(i);
        stk[stktop++] = i;
        intv.push_back(make_pair(nxt[i] - i, i));
    }
    //for (int i = 1; i <= n; i++) printf("%d ", nxt[i]);
    for (int i = 1; i <= n; i++) {
        ptr[i] = i + 1; ncost[i] = a[i];
    }
    sort(intv.begin(), intv.end());
    for (int i = 0; i < intv.size(); i++) {
        int from = intv[i].second;
        int to = from + intv[i].first;
        ll ccost = 0;
        int cur = from;
        while (cur < to) {
            ccost += ncost[cur];
            cur = ptr[cur];
        }
        //printf("%d %d %lld %lld\n", from, to, ccost, b[from]);
        ccost = min(ccost, b[from]);
        ptr[from] = to;
        ncost[from] = ccost;
    }
    set<pair<int, int> > query_pairs;
    set<int> values, neg_values;
    query_pairs.insert(make_pair(1, n + 1));
    values.insert(1);
    values.insert(n + 1);
    neg_values.insert(-1);
    neg_values.insert(-n - 1);
    for (int i = 1; i <= q; i++) {
        int x; scanf("%d", &x);
        if (x == 1) continue;
        int removing = 1;
        if (values.count(x)) {
            removing = -1; values.erase(x);
            neg_values.erase(-x);
        }
        int prev_val = -*neg_values.lower_bound(-x);
        int next_val = *values.lower_bound(x);
        query_pairs.insert(make_pair(prev_val, next_val));
        query_pairs.insert(make_pair(prev_val, x));
        query_pairs.insert(make_pair(x, next_val));
        change[i].push_back(make_triple(prev_val, next_val, -removing));
        change[i].push_back(make_triple(prev_val, x, removing));
        change[i].push_back(make_triple(x, next_val, removing));
        if (removing == 1) {
            values.insert(x);
            neg_values.insert(-x);
        }
    }
    /*for (int i = 1; i <= q; i++) {
        for (int j = 0; j < change[i].size(); j++) {
            printf("%d %d %d\n", change[i][j].from, change[i][j].to, change[i][j].weight);
        }
    }*/
    while (!query_pairs.empty()) {
        pair<int, int> x = *query_pairs.begin();
        qryprev[x.second].push_back(x.first);
        query_pairs.erase(query_pairs.begin());
    }
    map<pair<int, int>, ll> intvans;
    for (int i = 1; i <= n; i++) {
        func[i] = i + 1;
        fcost[i] = a[i];
    }
    init_func();
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j < nxtprev[i].size(); j++) {
            int pre = nxtprev[i][j];
            modify_func(pre, i, ncost[pre]);
        }
        //for (int x = 1; x <= n; x++) {
            //printf(": %d %lld %d %lld\n", func[x], fcost[x], nxtblock[x], nxtcost[x]);
        //}
        for (int j = 0; j < qryprev[i].size(); j++) {
            int pre = qryprev[i][j];
            intvans[make_pair(pre, i)] = query_func(pre, i);
            //printf("%d -> %d: %lld\n", pre, i, intvans[make_pair(pre, i)]);
        }
    }
    ll curans = intvans[make_pair(1, n + 1)];
    for (int i = 1; i <= q; i++) {
        for (int j = 0; j < change[i].size(); j++) {
            Triple t = change[i][j];
            curans += intvans[make_pair(t.from, t.to)] * (ll)t.weight;
        }
        printf("%lld\n", curans);
    }
    return 0;
}