/// Aho-Corasick
/// https://codeforces.com/problemset/problem/434/C
/// https://gspvh21.contest.codeforces.com/group/ABXsSubxJG/contest/375889/problem/G
#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=(l); i<=(r); ++i)
#define REP(i,l,r) for(int i=(l); i<(r); ++i)
#define FORD(i,r,l) for(int i=(r); i>=(l); --i)
#define REPD(i,r,l) for(int i=(r)-1; i>=(l); --i)
using namespace std;
const int N = 205, M = 505, INF = 0x3c3c3c3c, MOD = 1e9 + 7;
int n, m, k;
int lenL, lenR, aL[N], aR[N];
int a[N];

typedef struct Node *TNode;
int cnode;
TNode List[N];

struct Node {
    Node *fail, *child[20], *next[20];
    int sum_matches, id;
    Node() {
        sum_matches = 0;
        fail = nullptr;
        fill(child, child + 20, nullptr);
        fill(next, next + 20, nullptr);

        id = cnode++;
        List[id] = this;
    }
};
TNode root = new Node();

void add(int len, int arr[], int val) {
    TNode u = root;
    REP(i, 0, len) {
        int c = arr[i];
        if (u->child[c] == nullptr) u->child[c] = new Node();
        u = u->child[c];
    }
    u->sum_matches += val;
}

void Init_Aho() {
    root->fail = root;
    fill(root->next, root->next + m, root);

    queue<TNode> Q;
    Q.push(root);
    while (!Q.empty()) {
        TNode u = Q.front(); Q.pop();
        REP(c, 0, m) {
            if (u->child[c] != nullptr) {
                u->child[c]->fail = u->fail->next[c];
                u->next[c] = u->child[c];
                Q.push(u->child[c]);
            }
            else u->next[c] = u->fail->next[c];
        }
        u->sum_matches = min(u->sum_matches + u->fail->sum_matches, INF);
    }
}

void Enter() {
    cin >> n >> m >> k;
    cin >> lenL;
    REPD(i, lenL, 0) cin >> aL[i];
    cin >> lenR;
    REPD(i, lenR, 0) cin >> aR[i];

    FOR(i, 1, n) {
        int len, val;
        cin >> len;
        REP(j, 0, len) cin >> a[j];
        cin >> val;
        add(len, a, val);
    }
}

int res, dp[N][M][N][2][2];
/// i    - val - id - typex - typey
/// lenR -  k  - id - 0/1   - 0/1

pair<int, int> getnext(int i, int okx, int oky, int c) {
    if (okx && c < aL[i]) return {-1, -1};
    if (oky && c > aR[i]) return {-1, -1};
    int u = (okx && c == aL[i]);
    int v = (oky && c == aR[i]);
    return {u, v};
}

void Process() {
    dp[lenR][0][0][1][1] = 1;
    TNode rfirst = root->next[0];
    REPD(i, lenR, lenL) {
        if (rfirst->sum_matches <= k)
            dp[i][rfirst->sum_matches][rfirst->id][1][0] += MOD - 1;
        dp[i][0][0][1][0] += 1;
    }

    REPD(i, lenR, 0) FOR(val, 0, k) REP(id, 0, cnode) REP(okx, 0, 2) REP(oky, 0, 2) REP(c, 0, m) {
        if (dp[i + 1][val][id][okx][oky] == 0)
            continue;
        auto [okx2, oky2] = getnext(i, okx, oky, c);
        if (okx2 == -1) continue;

        TNode v = List[id]->next[c];
        int tmp = val + v->sum_matches;
        int id2 = v->id;

        if (tmp > k) continue;
        (dp[i][tmp][id2][okx2][oky2] += dp[i + 1][val][id][okx][oky]) %= MOD;
    }
    FOR(val, 0, k) REP(id, 0, cnode) REP(okx, 0, 2) REP(oky, 0, 2) (res += dp[0][val][id][okx][oky]) %= MOD;
    cout << res;
}

int main()
{
    #define file "G"
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    if (fopen(file".inp","r")) {
        freopen(file".inp","r",stdin);
        freopen(file".out","w",stdout);
    }
    Enter();
    Init_Aho();
    Process();
}