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

const vector<vector<pair<int, int>>> cover{
    {{0, 0}, {0, 1}},
    {{1, 0}},
    {{1, 0}, {1, 1}, {1, 2}},
    {{0, 1}, {2, 1}},
    {{2, 1}, {2, 2}},
    {{1, 2}}
};

template<int MOD>
struct Matrix {
    int n, m;
    vector<vector<long long>> mat;

    Matrix(int _n, int _m) : n(_n), m(_m), mat(n, vector<long long>(m)) {}

    Matrix operator += (const Matrix &other) {
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++) {
                mat[i][j] += other.mat[i][j];
                if (mat[i][j] >= MOD) mat[i][j] -= MOD;
            }
        return *this;
    }

    Matrix operator -= (const Matrix &other) {
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++) {
                mat[i][j] -= other.mat[i][j];
                if (mat[i][j] < 0) mat[i][j] += MOD;
            }
        return *this;
    }

    Matrix operator * (const Matrix &other) const {
        Matrix ret(n, other.m);
        for (int i=0; i<n; i++)
            for (int k=0; k<m; k++)
                for (int j=0; j<other.m; j++) {
                    ret.mat[i][j] += mat[i][k] * other.mat[k][j] % MOD;
                    if (ret.mat[i][j] >= MOD)
                        ret.mat[i][j] -= MOD;
                }
        return ret;
    }

    friend Matrix operator + (Matrix a, const Matrix &b) {
        return a += b;
    }

    friend Matrix operator - (Matrix a, const Matrix &b) {
        return a -= b;
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
            ret[i][i] = 1;
        while (b > 0) {
            if (b & 1)
                ret *= m;
            m *= m;
            b >>= 1;
        }
        return ret;
    }
};
typedef Matrix<1000000007> M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long m;
    cin >> n >> m;
    vector<array<long long, 3>> v;
    for (int i=0; i<n; i++) {
        int a;
        long long l, r;
        cin >> a >> l >> r;
        a--, l--, r--;
        v.push_back({l - 1, a, 0});
        v.push_back({l, a, 1});
        v.push_back({r, a, 2});
        v.push_back({r + 1, a, 3});
    }

    sort(v.begin(), v.end());
    M f(3, 3), ret(3, 1);
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            if (!(i == 0 && j == 2) && !(i == 2 && j == 0))
                f[i][j] = 1;
    ret[1][0] = 1;
    vector<int> cnt(3), cnt2(3);
    vector<vector<int>> all(3, vector<int>(3));
    for (int i=0; i<(int)v.size(); ) {
        ret = power(f, v[i][0] - (i > 0 ? v[i-1][0] : 0)) * ret;
        int j = i;
        while (j < (int) v.size() && v[i][0] == v[j][0]) {
            if (v[j][2] == 0) {
                if (++cnt[v[j][1]] == 1)
                    for (const auto &p : cover[2*v[j][1]])
                        if (++all[p.first][p.second] == 1)
                            f[p.first][p.second] = 0;
            } else if (v[j][2] == 1) {
                if (++cnt2[v[j][1]] == 1)
                    for (const auto &p : cover[2*v[j][1]+1])
                        if (++all[p.first][p.second] == 1)
                            f[p.first][p.second] = 0;
            } else if (v[j][2] == 2) {
                if (--cnt[v[j][1]] == 0)
                    for (const auto &p : cover[2*v[j][1]])
                        if (--all[p.first][p.second] == 0)
                            f[p.first][p.second] = 1;
            } else {
                if (--cnt2[v[j][1]] == 0)
                    for (const auto &p : cover[2*v[j][1]+1])
                        if (--all[p.first][p.second] == 0)
                            f[p.first][p.second] = 1;
            }
            j++;
        }
        i = j;
    }
    ret = power(f, m - 1 - v.back()[0]) * ret;
    cout << ret[1][0] << "\n";

    return 0;
}