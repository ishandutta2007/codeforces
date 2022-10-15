#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>
#include <map>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

typedef pair<int, int> Node;

ll pwr3[35];

Node pre(Node node)
{
    int x = node.first, y = node.second;
        if (y == 0 || ((x & (-x)) < (y & (-y)) && x > 0)) {
            x--;
        } else {
            y--;
        }
    return make_pair(x, y);
}

int depth(Node node)
{
    return node.first + node.second;
}

Node lca_brute_force(Node a, Node b)
{
    //debug("lca enter");
    if (depth(a) < depth(b)) swap(a, b);
    //debug("%d %d\n", depth(a), depth(b));
    int amt = depth(a) - depth(b);
    for (int i = 0; i < amt; i++) {
        a = pre(a);
    }
    //debug("%d %d\n", depth(a), depth(b));
    while (a != b) {
        a = pre(a); b = pre(b);
    }
    //debug("lca exit");
    return a;
}

/*Node lcabit(Node a, Node b, int level)
{
    if (a == b) return a;
    int bit = (1 << level);
    int vala = ((a.first & bit) ? 1 : 0) + ((a.second & bit) ? 2 : 0);
    int valb = ((b.first & bit) ? 1 : 0) + ((b.second & bit) ? 2 : 0);
    if (vala > valb) swap(a, b);
    if (vala == 0) {
        if (valb == 0) {
            return lcabit(a, b, level - 1);
        } else if (valb == 1) {
            int j;
            for (j = bit - 1; j >= 0; j--) {
                if (b.second & (1 << j)) break;
            }
            ansx |= (~((1 << (j + 1)) - 1)) & ((1 << (bit + 1)) - 1) & b.first;
            return make_pair(, 0);
        }
    }
}*/

Node lca(Node a, Node b)
{
    int a_on = a.first | a.second;
    int b_on = b.first | b.second;
    int ansx = 0, ansy = 0;
    for (int i = 30; i >= 0; i--) {
        int bit = (1 << i);
        if (!((a_on | b_on) & bit)) continue;
        if ((a_on & bit) && (b_on & bit)) {
            if ((a.first & bit) && (b.second & bit)) return make_pair(ansx, ansy);
            if ((a.second & bit) && (b.first & bit)) return make_pair(ansx, ansy);
            if (a.first & bit) {
                ansx |= bit;
            } else {
                ansy |= bit;
            }
            continue;
        }
        if (b_on & bit) {
            swap(a, b); swap(a_on, b_on);
        }
        bool postswap = false;
        if (a.second & bit) {
            swap(a.first, a.second);
            swap(b.first, b.second);
            swap(ansx, ansy);
            postswap = true;
        }
        //printf("%d %d %d %d %d %d\n", a.first, a.second, b.first, b.second, ansx, ansy);
        int j;
        for (j = i - 1; j >= 0; j--) {
            if (b.second & (1 << j)) break;
        }
        ansx |= (~((1 << (j + 1)) - 1)) & ((1 << (i + 1)) - 1) & b.first;
        if (postswap) swap(ansx, ansy);
        return make_pair(ansx, ansy);
    }
    return make_pair(ansx, ansy);
}

ll dfs_order(Node node, int level)
{
    if (node.first == 0 && node.second == 0) return 0;
    if (node.first > node.second) {
        return dfs_order(make_pair(node.second, node.first), level) + (pwr3[level] - 1LL) / 2LL;
    }
    if (node.first == 0) return node.second;
    if (node.second & (1 << (level - 1))) return dfs_order(make_pair(node.first, node.second - (1 << (level - 1))), level - 1) + (1LL << (level - 1));
    return dfs_order(node, level - 1) + pwr3[level - 1];
}

map<Node, ll> dfsorder;

bool cmp(Node a, Node b)
{
    if (!dfsorder.count(a)) dfsorder[a] = dfs_order(a, 30);
    if (!dfsorder.count(b)) dfsorder[b] = dfs_order(b, 30);
    //printf("%lld %lld\n", dfsorder[a], dfsorder[b]);
    return dfsorder[a] < dfsorder[b];
}

int m;
Node nodes[200005];
Node onodes[200005];
Node stk[300005];
int stktop = 0;
map<Node, vector<Node> > tree;
map<Node, int> off;
map<Node, int> islca;

set<int> flips;

int ans = 0;

void flip(int val)
{
    //printf("%d\n", val);
    if (val < 0) return;
    if (flips.count(val)) {
        ans--; flips.erase(val);
    } else {
        ans++; flips.insert(val);
    }
}

int dfs(Node node)
{
    //printf("%d %d\n", node.first, node.second);
    //printf("(");
    int toff = off[node];
    for (int i = 0; i < tree[node].size(); i++) {
        int offv = dfs(tree[node][i]);
        if (offv > 0) {
            //printf("%d %d -> %d %d\n", node.first, node.second, tree[node][i].first, tree[node][i].second);
            flip(depth(tree[node][i]));
            flip(depth(node));
        }
        toff += offv;
    }
    if (islca[node] && !toff) {
        //printf("flip %d %d\n", node.first, node.second);
        flip(depth(node));
        flip(depth(node) - 1);
    }
    //printf(")");
    return toff;
}

int main()
{
    pwr3[0] = 1;
    for (int i = 1; i <= 30; i++) pwr3[i] = 3LL * pwr3[i-1];
    //Node mynode = lca(make_pair(63, 0), make_pair(31, 0));
    //printf("%d %d\n", mynode.first, mynode.second);
    /*for (int i = 0; i < 128; i++) {
        for (int j = 0; j < 128; j++) {
            if (i & j) continue;
            for (int k = 0; k < 128; k++) {
                for (int l = 0; l < 128; l++) {
                    if (k & l) continue;
                    Node n1, n2;
                    n1.first = i; n1.second = j;
                    n2.first = k; n2.second = l;
                    if (lca_brute_force(n1, n2) != lca(n1, n2)) {
                        printf("%d %d %d %d\n", i, j, k, l);
                    }
                }
            }
        }
    }
    debug("done checking");*/
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d%d", &(nodes[2*i-1].first), &(nodes[2*i-1].second),
                          &(nodes[2*i].first), &(nodes[2*i].second));
    }
    for (int i = 1; i <= 2 * m; i++) onodes[i] = nodes[i];
    sort(nodes + 1, nodes + 2 * m + 1, cmp);
    for (int i = 1; i <= 2 * m; i++) {
        if (nodes[i] == nodes[i-1]) continue;
        //printf("%d %d\n", nodes[i].first, nodes[i].second);
        /*if (nodes[i] == make_pair(15, 0)) {
            for (int x = 0; x <= stktop; x++) {
                printf("!%d %d\n", stk[x].first, stk[x].second);
            }
        }*/
        Node lcanode = lca(nodes[i], stk[stktop]);
        while (depth(stk[stktop]) > depth(lcanode)) {
            if (depth(stk[stktop - 1]) < depth(lcanode)) {
                //printf("a %d %d -> %d %d\n", lcanode.first, lcanode.second, stk[stktop].first, stk[stktop].second);
                tree[lcanode].push_back(stk[stktop]);
            } else {
                //printf("b %d %d -> %d %d\n", stk[stktop - 1].first, stk[stktop - 1].second, stk[stktop].first, stk[stktop].second);
                tree[stk[stktop - 1]].push_back(stk[stktop]);
            }
            stktop--;
        }
        if (stk[stktop] != lcanode) {
            stktop++; stk[stktop] = lcanode;
        }
        stktop++; stk[stktop] = nodes[i];
    }
    while (stktop) {
        tree[stk[stktop - 1]].push_back(stk[stktop]);
        stktop--;
    }
    for (int i = 1; i <= m; i++) {
        Node lcanode = lca(onodes[i * 2 - 1], onodes[i * 2]);
        //printf("!%d %d\n", lcanode.first, lcanode.second);
        off[onodes[i * 2 - 1]]++;
        off[onodes[i * 2]]++;
        off[lcanode] -= 2;
        islca[lcanode]++;
    }
    dfs(make_pair(0, 0));
    printf("%d", ans);
    return 0;
}