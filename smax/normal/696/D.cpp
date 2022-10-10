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

#define MAX 205
#define ALPHA 26

const long long INF = 1e18;

int id = 1, trie[MAX][ALPHA], link[MAX];
long long val[MAX];

void add(const string &s, int a) {
    int u = 0;
    for (char c : s) {
        if (!trie[u][c-'a'])
            u = trie[u][c-'a'] = id++;
        else
            u = trie[u][c-'a'];
    }
    val[u] += a;
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
            val[u] += val[link[u]];
    }
}

struct Matrix {
    int n, m;
    vector<vector<long long>> mat;

    Matrix(int _n, int _m) : n(_n), m(_m), mat(n, vector<long long>(m, -INF)) {}

    Matrix operator * (const Matrix &other) const {
        Matrix ret(n, other.m);
        for (int i=0; i<n; i++)
            for (int k=0; k<m; k++)
                for (int j=0; j<other.m; j++)
                    ret.mat[i][j] = max(ret.mat[i][j], mat[i][k] + other.mat[k][j]);
        return ret;
    }

    Matrix operator *= (const Matrix &other) {
        return *this = *this * other;
    }

    vector<long long>& operator [] (int i) {
        return mat[i];
    }

    friend Matrix power(Matrix m, long long b) {
        Matrix ret(m.n, m.m);
        for (int i=0; i<m.n; i++)
            ret[i][i] = 0;
        while (b > 0) {
            if (b & 1)
                ret *= m;
            m *= m;
            b >>= 1;
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    long long l;
    cin >> n >> l;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        add(s, a[i]);
    }

    gen();

    Matrix m(id, id);
    for (int i=0; i<id; i++)
        for (int j=0; j<ALPHA; j++)
            m[trie[i][j]][i] = val[trie[i][j]];
    Matrix dp(id, 1);
    dp[0][0] = 0;

    dp = power(m, l) * dp;

    long long ret = 0;
    for (int i=0; i<id; i++)
        ret = max(ret, dp[i][0]);
    cout << ret << "\n";

    return 0;
}