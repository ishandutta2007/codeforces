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

const int MAXN = 3e5 + 5;
const double PI = acos(-1);
const cd ID(1, 0);

int len[MAXN];
cd st[4*MAXN], lazy[4*MAXN];

void build(int p, int l, int r) {
    lazy[p] = ID;
    if (l == r) {
        st[p] = ID;
        return;
    }
    int m = (l + r) / 2;
    build(2*p, l, m);
    build(2*p+1, m+1, r);
    st[p] = st[2*p] + st[2*p+1];
}

void push(int p, int l, int r) {
    if (lazy[p] != ID) {
        st[p] *= lazy[p];
        if (l != r) {
            lazy[2*p] *= lazy[p];
            lazy[2*p+1] *= lazy[p];
        }
        lazy[p] = ID;
    }
}

void update(int p, int l, int r, int i, int j, const cd &val) {
    push(p, l, r);
    if (i > r || j < l)
        return;
    if (i <= l && r <= j) {
        lazy[p] *= val;
        push(p, l, r);
        return;
    }
    int m = (l + r) / 2;
    update(2*p, l, m, i, j, val);
    update(2*p+1, m+1, r, i, j, val);
    st[p] = st[2*p] + st[2*p+1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        len[i] = 1;
    build(1, 0, n-1);
    cout << fixed << setprecision(10);
    for (int i=0; i<m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        y--;
        if (x == 1) {
            update(1, 0, n-1, y, y, (double) (len[y] + z) / len[y]);
            len[y] += z;
        } else {
            double ang = (360 - z) * PI / 180;
            update(1, 0, n-1, y, n-1, cd(cos(ang), sin(ang)));
        }
        cout << st[1].real() << " " << st[1].imag() << "\n";
    }

    return 0;
}