#include <bits/stdc++.h>

using namespace std;

#define ve vector
#define pa pair
#define tu tuple

#define assert_m(exp, msg) assert(((void)msg, exp))

typedef uint32_t uint;
typedef int64_t ll;

typedef ve<int> vi;
typedef ve<vi> v2i;
typedef pa<int, int> pii;

class SpanTreeInfo {
public:
    explicit SpanTreeInfo(const v2i& g)
        : numV(g.size())
        , par(numV, -1)
        , size(numV, 0)
        , roots()
        , treeGraph(numV)
    {
        roots.reserve(numV);
        usedV.assign(numV, 0);
        for (size_t i = 0; i < numV; ++i) {
            if (!usedV[i]) {
                roots.push_back(i);
                InitDFS(i, g);
            }
        }
        usedV.clear();
    }

private:
    void InitDFS(int v, const v2i& g) {
        usedV[v] = 1;
        size[v] = 1;
        for (int to : g[v]) {
            if (!usedV[to]) {
                treeGraph[v].push_back(to);
                InitDFS(to, g);
                par[to] = v;
                size[v] += size[to];
            }
        }
    }

public:
    size_t numV;
    vi par;
    vi size;
    vi roots;
    v2i treeGraph;

private:
    ve<char> usedV;
};

class LabelingInfo {
public:
    explicit LabelingInfo(const SpanTreeInfo& tInfo)
        : p(tInfo.numV, -1)
        , q(tInfo.numV, -1)
    {
        labelTs = 0;
        for (int v : tInfo.roots) {
            if (tInfo.size[v] == 1) {
                p[v] = q[v] = labelTs++;
            } else {
                StarSplitDFS(v, /* usePar = */ false, tInfo);
            }
        }
    }

private:
    void StarSplitDFS(int v, bool usePar, const SpanTreeInfo& tInfo) {
        // Invariant: this function don't called for v with no children
        vi noChild, hasChild;
        noChild.reserve(tInfo.size[v] + 1);
        hasChild.reserve(tInfo.size[v]);
        for (int to : tInfo.treeGraph[v]) {
            if (tInfo.size[to] == 1) {
                noChild.push_back(to);
            } else { // tInfo.size[to] > 1
                hasChild.push_back(to);
            }
        }
        if (usePar) {
            // use parent as leaf of star
            noChild.push_back(tInfo.par[v]);
        }
        if (!noChild.empty()) {
            const auto& leaves = noChild;
            p[v] = labelTs;
            for (int leaf : leaves) {
                q[leaf] = labelTs++;
                p[leaf] = labelTs;
            }
            q[v] = labelTs++;
        } else {
            // Use some son from `hasChild` as root of the star
            // and `v` as leaf in this star
            auto goodSon = hasChild.back();
            hasChild.pop_back();
            StarSplitDFS(goodSon, true, tInfo);
        }
        for (int son : hasChild) {
            StarSplitDFS(son, false, tInfo);
        }
    }

public:
    vi p;
    vi q;

private:
    size_t labelTs = 0;
};

void
solve()
{
    int n, m;
    cin >> n >> m;
    v2i g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    v2i gv(n);
    vi mex_v(n, -1);
    for (int i = 0; i < n; ++i) {
        mex_v[i] = i;
        for (int to : g[i]) {
            mex_v[to] = i;
        }
        int v = 0;
        while (v < n && mex_v[v] == i) ++v;
        if (v < n) {
            gv[v].push_back(i); // add only one edge
        }
    }
    const SpanTreeInfo tInfo(gv);
    const LabelingInfo lInfo(tInfo);
    for (int x : lInfo.p) {
        cout << x + 1 << ' ';
    } cout << '\n';
    for (int x : lInfo.q) {
        cout << x + 1 << ' ';
    } cout << '\n';
}

int
main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        solve();
    }
    return 0;
}