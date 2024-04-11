#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int st[400000][26], lazy[400000][26], cnt[26];

void build(int p, int l, int r, const string &s) {
    if (l == r) {
        st[p][s[l]-'a'] = 1;
        return;
    }

    int m = (l + r) / 2;
    build(2*p, l, m, s);
    build(2*p+1, m+1, r, s);
    for (int c=0; c<26; c++)
        st[p][c] = st[2*p][c] + st[2*p+1][c];
}

void push(int p, int l, int r, int c) {
    if (lazy[p][c] != -1) {
        st[p][c] = lazy[p][c] * (r - l + 1);
        if (l != r)
            lazy[2*p][c] = lazy[2*p+1][c] = lazy[p][c];
        lazy[p][c] = -1;
    }
}

int query(int p, int l, int r, int i, int j, int c) {
    push(p, l, r, c);

    if (i > r || j < l)
        return 0;
    if (i <= l && r <= j)
        return st[p][c];

    int m = (l + r) / 2;
    return query(2*p, l, m, i, j, c) + query(2*p+1, m+1, r, i, j, c);
}

void update(int p, int l, int r, int i, int j, int c, int val) {
    push(p, l, r, c);

    if (i > r || j < l)
        return;
    if (i <= l && r <= j) {
        st[p][c] = val * (r - l + 1);
        if (l != r)
            lazy[2*p][c] = lazy[2*p+1][c] = val;
        return;
    }

    int m = (l + r) / 2;
    update(2*p, l, m, i, j, c, val);
    update(2*p+1, m+1, r, i, j, c, val);
    st[p][c] = st[2*p][c] + st[2*p+1][c];
}

void down(int p, int l, int r, string &s) {
    for (int c=0; c<26; c++)
        push(p, l, r, c);

    if (l == r) {
        for (int c=0; c<26; c++)
            if (st[p][c])
                s[l] = c + 'a';
        return;
    }

    int m = (l + r) / 2;
    down(2*p, l, m, s);
    down(2*p+1, m+1, r, s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, q;
    string s;
    cin >> n >> q >> s;

    memset(lazy, -1, sizeof(lazy));
    build(1, 0, n-1, s);

    while (q--) {
        int i, j, k;
        cin >> i >> j >> k;
        i--, j--;

        for (int c=0; c<26; c++)
            cnt[c] = query(1, 0, n-1, i, j, c);

        if (k == 1) {
            int idx = i;
            for (int c=0; c<26; c++)
                if (cnt[c] > 0) {
                    update(1, 0, n-1, i, j, c, 0);
                    update(1, 0, n-1, idx, idx+cnt[c]-1, c, 1);
                    idx += cnt[c];
                }
        } else {
            int idx = j;
            for (int c=0; c<26; c++)
                if (cnt[c] > 0) {
                    update(1, 0, n-1, i, j, c, 0);
                    update(1, 0, n-1, idx-cnt[c]+1, idx, c, 1);
                    idx -= cnt[c];
                }
        }
    }
    down(1, 0, n-1, s);

    cout << s << "\n";

    return 0;
}