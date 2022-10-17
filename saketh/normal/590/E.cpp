#include <bits/stdc++.h>
using namespace std;

namespace aho_corasick {
    const int SIGMA = 2;
    const int TOTL = 1e7 + 100;

    struct node {
        int link[SIGMA];
        int suff, dict, patt;
        node() { 
            suff = 0, dict = 0, patt = -1;
        }
        // link[]: contains trie links + failure links
        // suff: link to longest proper suffix that exists in the trie
        // dict: link to longest suffix that exists in the dictionary
        // patt: index of this node's word in the dictionary
    };

    int tail = 1;
    vector<node> trie(TOTL);
    vector<string> patterns;

    void add_pattern(string &s) {
        int loc = 0;
        for (char c : s) {
            int &nloc = trie[loc].link[c-'a'];
            if (!nloc) nloc = tail++;
            loc = nloc;
        }

        trie[loc].dict = loc;
        trie[loc].patt = patterns.size();
        patterns.push_back(s);
    }

    void calc_links() {
        queue<int> bfs({0});

        while (!bfs.empty()) {
            int loc = bfs.front(); bfs.pop();
            int fail = trie[loc].suff;

            if (!trie[loc].dict) 
                trie[loc].dict = trie[fail].dict;

            for (int c = 0; c < SIGMA; c++) {
                int &succ = trie[loc].link[c];
                if (succ) {
                    trie[succ].suff = loc ? trie[fail].link[c] : 0;
                    bfs.push(succ);
                } else succ = trie[fail].link[c];
            }
        }
    }

    void match(string &s, vector<bool> &matches) {
        int loc = 0;

        for (char c : s) {
            loc = trie[loc].link[c-'a'];

            for (int dm = trie[loc].dict; dm; dm = trie[trie[dm].suff].dict) {
                if (matches[trie[dm].patt]) break;
                matches[trie[dm].patt] = true;
            }
        }
    }
}

struct bipartite_graph {
    int A, B;
    vector<vector<int>> adj;

    bipartite_graph(int _A, int _B) {
        A = _A, B = _B;
        adj.resize(A + B); 
    }

    void edge(int i, int j) {
        adj[i].push_back(A+j);
        adj[A+j].push_back(i);
    }

    vector<int> visit, match;

    bool augment(int loc, int run) {
        if(visit[loc] == run) return false;
        visit[loc] = run;

        for (int nbr : adj[loc]) {
            if (match[nbr] == -1 || augment(match[nbr], run)) {
                match[loc] = nbr, match[nbr] = loc;
                return true;
            }
        }

        return false;
    }

    int matching() {
        visit = vector<int>(A+B, -1);
        match = vector<int>(A+B, -1); 

        int ans = 0;
        for (int i = 0; i < A; i++) 
            ans += augment(i, i);
        return ans;
    }
};

vector<int> width(vector<vector<int>> poset) {
    int N = poset.size();
    bipartite_graph g(N, N);

    for (int i = 0; i < N; i++) {
        for (int j : poset[i])
            g.edge(j, i);
    }

    g.matching();

    vector<bool> vis[2];
    vis[false].resize(2 * N, false);
    vis[true].resize(2 * N, false);

    for (int i = 0; i < N; i++) {
        if (g.match[i] != -1) continue;
        if (vis[false][i]) continue;

        queue<pair<bool, int>> bfs;
        bfs.push(make_pair(false, i));
        vis[false][i] = true;

        while (!bfs.empty()) {
            bool inm = bfs.front().first;
            int loc = bfs.front().second;
            bfs.pop();

            for (int nbr : g.adj[loc]) {
                if (vis[!inm][nbr]) continue;
                if ((g.match[loc] == nbr) ^ inm) continue;

                vis[!inm][nbr] = true;
                bfs.push(make_pair(!inm, nbr));
            }
        }
    }

    vector<bool> inz(2 * N, false);
    for (int i = 0; i < 2 * N; i++)
        inz[i] = vis[true][i] || vis[false][i];

    vector<bool> ink(N, false);

    for (int i = 0; i < N; i++)
        if (!inz[i])
            ink[i]= true;

    for (int i = N; i < 2 * N; i++) 
        if (inz[i])
            ink[i - N] = true;

    vector<int> res;
    for (int i = 0; i < N; i++) {
        if (!ink[i])
            res.push_back(i);
    }
    return res;
}

const int MAXN = 800;

int N;
string words[MAXN];
vector<bool> subst[MAXN];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> words[i];
        aho_corasick::add_pattern(words[i]);
    }

    aho_corasick::calc_links();

    vector<vector<int>> poset(N);

    for (int i = 0; i < N; i++) {
        subst[i].resize(N);
        aho_corasick::match(words[i], subst[i]);

        for (int j = 0; j < N; j++)
            if (subst[i][j] && i != j)
                poset[i].push_back(j);
    }

    vector<int> res = width(poset);

    cout << res.size() << "\n";
    for (int v : res) cout << v + 1 << " ";
    cout << "\n";
}