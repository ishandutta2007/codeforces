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

const int MAX = 9e6 + 5;
const int LOG = 30;

int id = 1, trie[MAX][2], cnt[MAX];
long long tot[LOG][2];

void add(int x) {
    int u = 0;
    for (int i=LOG-1; i>=0; i--) {
        int j = (x & (1 << i)) > 0;
        tot[i][j] += cnt[trie[u][1-j]];
        if (!trie[u][j])
            trie[u][j] = id++;
        u = trie[u][j];
        cnt[u]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        add(a);
    }

    int x = 0;
    long long ret = 0;
    for (int i=0; i<LOG; i++) {
        if (tot[i][0] > tot[i][1]) {
            x |= 1 << i;
            ret += tot[i][1];
        } else {
            ret += tot[i][0];
        }
    }
    cout << ret << " " << x << "\n";

    return 0;
}