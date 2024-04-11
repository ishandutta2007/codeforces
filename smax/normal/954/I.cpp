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

typedef complex<double> cd;

const double PI = acos(-1);

void fft(vector<cd> &a, bool inv) {
    int n = a.size();
    for (int i=1, j=0; i<n; i++) {
        int bit = n >> 1;
        for (; j&bit; bit>>=1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len=2; len<=n; len*=2) {
        double ang = 2 * PI / len * (inv ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i=0; i<n; i+=len) {
            cd w(1);
            for (int j=0; j<len/2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (inv)
        for (cd &x : a)
            x /= n;
}

vector<long long> mul(const vector<long long> &a, const vector<long long> &b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < (int) a.size() + (int) b.size())
        n *= 2;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i=0; i<n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<long long> ret(n);
    for (int i=0; i<n; i++)
        ret[i] = llround(fa[i].real());
    return ret;
}

template<int SZ>
struct DSU {
    int comp, par[SZ], sz[SZ];

    void init(int n) {
        comp = n;
        for (int i=0; i<n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find(int u) {
        if (u != par[u])
            par[u] = find(par[u]);
        return par[u];
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        comp--;
        if (sz[u] < sz[v])
            swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

DSU<6> ds[125005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    reverse(s.begin(), s.end());
    for (int i=0; i<n; i++)
        ds[i].init(6);
    for (int a=0; a<6; a++)
        for (int b=0; b<6; b++)
            if (a != b) {
                vector<long long> polyS(n), polyT(m);
                for (int i=0; i<n; i++)
                    polyS[i] = s[i] - 'a' == a;
                for (int i=0; i<m; i++)
                    polyT[i] = t[i] - 'a' == b;
                vector<long long> ret = mul(polyS, polyT);
                for (int i=m-1; i<n; i++)
                    if (ret[i] > 0)
                        ds[n-i-1].unite(a, b);
            }

    for (int i=0; i<=n-m; i++)
        cout << 6 - ds[i].comp << " ";
    cout << "\n";

    return 0;
}