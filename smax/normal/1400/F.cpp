#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

#define MAX 10005
#define ALPHA 9

int id = 1, trie[MAX][ALPHA], link[MAX];
bool nd[MAX];

void add(const string &s) {
    int u = 0;
    for (char c : s) {
        if (!trie[u][c-'1'])
            u = trie[u][c-'1'] = id++;
        else
            u = trie[u][c-'1'];
    }
    nd[u] = true;
}

void gen() {
    link[0] = -1;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int j=0; j<ALPHA; j++) {
            int v = trie[u][j];
            if (v) {
                link[v] = (link[u] == -1 ? 0 : trie[link[u]][j]);
                q.push(v);
            } else if (u) {
                trie[u][j] = trie[link[u]][j];
            }
        }
        if (link[u] != -1)
            nd[u] |= nd[link[u]];
    }
}

int x;
string cur;

void comp(int sum) {
    if (sum == x) {
        bool ok = true;
        for (int i=0; i<(int)cur.length(); i++) {
            int tot = 0;
            for (int j=i; j<(int)cur.length(); j++) {
                tot += cur[j] - '0';
                if (tot != x && x % tot == 0) {
                    ok = false;
                    break;
                }
            }
            if (!ok)
                break;
        }
        if (ok)
            add(cur);
        return;
    }
    for (int d=1; d<10 && sum+d<=x; d++) {
        cur += (char) (d + '0');
        comp(sum + d);
        cur.pop_back();
    }
}

int dp[1005][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    cin >> s >> x;

    comp(0);
    gen();

    memset(dp, 127, sizeof(dp));
    dp[0][0] = 0;
    for (int i=0; i<(int)s.length(); i++)
        for (int j=0; j<id; j++) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
            if (!nd[trie[j][s[i]-'1']])
                dp[i+1][trie[j][s[i]-'1']] = min(dp[i+1][trie[j][s[i]-'1']], dp[i][j]);
        }
    cout << *min_element(dp[s.length()], dp[s.length()] + id) << "\n";

    return 0;
}