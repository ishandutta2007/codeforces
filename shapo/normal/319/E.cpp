#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 200500;
const int MAXK = 262144;

struct List
{
    vector< int > comp_id;
} tree[2 * MAXK];

struct DSU_Node
{
    int par, rank;
    int left, right;
};

vector< DSU_Node > dsu;
int n;
int tp[MAXN];
int x[MAXN], y[MAXN];
int curk;

int
getPar(int x)
{
    if (dsu[x].par != x) {
        dsu[x].par = getPar(dsu[x].par);
    }
    return dsu[x].par;
}

void
link(int a, int b)
{
    if (dsu[a].rank >= dsu[b].rank) {
        dsu[b].par = a;
    } else {
        dsu[a].par = b;
    }
    if (dsu[a].rank == dsu[b].rank) {
        dsu[a].rank++;
    }
    int par = getPar(a);
    dsu[par].left = min(dsu[a].left, dsu[b].left);
    dsu[par].right = max(dsu[a].right, dsu[b].right);
}

bool
isCover(int from, int to)
{
    return (dsu[from].left <= dsu[to].left && dsu[from].right >= dsu[to].right);
}

void
updateCover(int from, int to, int id)
{
    from += curk - 1;
    to += curk - 1;
    while (from < to) {
        if (from % 2 == 1) {
            tree[from].comp_id.push_back(id);
        } 
        from = (from + 1) / 2;
        if (to % 2 == 0) {
            tree[to].comp_id.push_back(id);
        }
        to = (to - 1) / 2;
    }
    if (from == to) {
        tree[from].comp_id.push_back(id);
    }
}

void
addVertices(int pnt, vector< int > &res)
{
    pnt += curk - 1;
    while (pnt != 0) {
        res.insert(res.end(), tree[pnt].comp_id.begin(), tree[pnt].comp_id.end());
        tree[pnt].comp_id.clear();
        pnt /= 2;
    }
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector< int > all_coord;
    all_coord.reserve(50);
    for (int i = 0; i < n; ++i) {
        cin >> tp[i] >> x[i] >> y[i];
        if (tp[i] == 1) {
            all_coord.push_back(x[i]);
            all_coord.push_back(y[i]);
        }
    }
    sort(all_coord.begin(), all_coord.end());
    all_coord.resize(unique(all_coord.begin(), all_coord.end()) - all_coord.begin());
    for (int i = 0; i < n; ++i) {
        if (tp[i] == 1) {
            x[i] = lower_bound(all_coord.begin(), all_coord.end(), x[i]) - all_coord.begin() + 1;
            y[i] = lower_bound(all_coord.begin(), all_coord.end(), y[i]) - all_coord.begin() + 1;
        }
    }
    dsu.push_back(DSU_Node());
    curk = 2;
    while (curk < n) {
        curk *= 2;
    }
    for (int i = 1; i <= 2 * curk; ++i) {
        tree[i].comp_id.clear();
    }
    int cnt_v = 0;
    for (int i = 0; i < n; ++i) {
        if (tp[i] == 1) {
            cnt_v++;
            DSU_Node tmp = {cnt_v, 1, x[i], y[i]};
            dsu.push_back(tmp);
            vector< int > all_comps;
            addVertices(x[i], all_comps);
            addVertices(y[i], all_comps);
            for (vector< int >::const_iterator it = all_comps.begin(); it != all_comps.end(); ++it) {
                int aa = getPar(cnt_v), bb = getPar(*it);
                if (aa != bb) {
                    link(aa, bb);
                }
            }
            int new_comp = getPar(cnt_v);
            int left_bound = dsu[new_comp].left, right_bound = dsu[new_comp].right;
            updateCover(left_bound + 1, right_bound - 1, new_comp);
        } else {
            int a_comp = getPar(x[i]), b_comp = getPar(y[i]);
            if (isCover(b_comp, a_comp)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}