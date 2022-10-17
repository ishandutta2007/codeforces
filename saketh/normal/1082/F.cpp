#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vb = vector<bool>;
using vs = vector<string>;

template<int S> struct trie {
    struct node {
        int dep;
        int wt;
        int succ[S];
        node(int _dep = 0, int _wt = 0) : dep(_dep), wt(_wt) {
            memset(succ, 0xff, sizeof(succ));
        }
    };

    vector<node> nodes;
    trie() {
        nodes.push_back(node());
    }

    void insert(vi& word, int wt = 1, int loc = 0, int inx = 0) {
        if (inx == word.size()) {
            nodes[loc].wt += wt;
            return;
        }
        int& nxt = nodes[loc].succ[word[inx]];
        if (nxt == -1) {
            nxt = nodes.size();
            nodes.push_back(node(nodes[loc].dep + 1));
        }
        insert(word, wt, nxt, inx + 1);
    }
};

const int MAXN = 501;
const int MAXK = 11;
const int INF = 0x7f7f7f7f;

// dp[u][v][k] = min number of presses for all numbers in subtree of u
// if most recent ancestor having a button is v and we have k buttons left
int dp[MAXN][MAXN][MAXK];
int dp2[MAXN][MAXK];

int go(trie<10>& t, int loc, int anc, int rem) {
    int& res = dp[loc][anc][rem];
    if (res == INF) {
        if (anc != loc && rem > 0) {
            res = min(res, go(t, loc, loc, rem-1));
        }
        for (int ch : t.nodes[loc].succ) {
            if (ch == -1) continue;
            for (int give = 0; give <= rem; give++)
                go(t, ch, anc, give);
        }

        int x = 0;
        for (int ch : t.nodes[loc].succ) {
            if (ch == -1) continue;
            memset(dp2[x+1], 0x7f, sizeof(dp2[x+1]));
            for (int used = 0; used <= rem; used++) {
                for (int give = 0; used + give <= rem; give++) {
                    dp2[x+1][used+give] = min(dp2[x+1][used+give],
                            dp2[x][used] + dp[ch][anc][give]);
                }
            }
            x++;
        }

        int mine = (t.nodes[loc].dep - t.nodes[anc].dep);
        res = min(res, mine * t.nodes[loc].wt + dp2[x][rem]);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    cin >> N >> K;

    trie<10> t;
    for (int i = 0; i < N; i++) {
        string num;
        int wt;
        cin >> num >> wt;
        vi digs(num.size());
        for (int j = 0; j < num.size(); j++)
            digs[j] = num[j] - '0';
        t.insert(digs, wt);
    }

    memset(dp, 0x7f, sizeof(dp));
    cout << go(t, 0, 0, K) << endl;

    return 0;
}