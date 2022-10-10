#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

#define MAX 2700005
#define ALPHA 2

int l, id = 1, trie[MAX][ALPHA], cnt[MAX] = {};

void update(int n, int val) {
    int u = 0;
    cnt[u] += val;
    for (int i=26; i>=0; i--) {
        int j = (n & (1 << i)) > 0;
        if (trie[u][j] == -1)
            u = trie[u][j] = id++;
        else
            u = trie[u][j];
        cnt[u] += val;
    }
}

int query(int n) {
    int u = 0, ret = 0;
    for (int i=26; i>=0; i--) {
        int j = (n & (1 << i)) > 0;
        if (l & (1 << i)) {
            if (trie[u][j] != -1)
                ret += cnt[trie[u][j]];
            if (trie[u][1-j] == -1)
                return ret;
            u = trie[u][1-j];
        } else {
            if (trie[u][j] == -1)
                return ret;
            u = trie[u][j];
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    memset(trie, -1, sizeof(trie));

    int q;
    cin >> q;
    while (q--) {
        int type, p;
        cin >> type >> p;
        if (type == 1)
            update(p, 1);
        else if (type == 2)
            update(p, -1);
        else {
            cin >> l;
            cout << query(p) << "\n";
        }
    }

    return 0;
}