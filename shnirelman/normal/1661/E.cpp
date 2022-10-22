#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
//const int M = 998244353;
const int M = 32768;
const int N = 5e5 + 13;
const int LOGN = 20;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, n));
}

int inv(int n) {
    return pow2(n, M - 2);
}

mt19937 rnd(0);

struct Node {
    int res;
    //vector<int> lf, rg;
    int lf[3], rg[3];

    Node() {
        res = 0;
        for(int i = 0; i < 3; i++)
            lf[i] = rg[i] = -1;
        //lf.resize(3, -1);
        //rg.resize(3, -1);
    }
};
int p[12];

int getp(int x) {
//    cout << "getp " << x << ' ' << p[x] << endl;
    return (x == p[x] ? x : p[x] = getp(p[x]));
}

bool unite(int x, int y) {
//    cout << "unite " << x << ' ' << y << endl;
    x = getp(x);
    y = getp(y);
//cout << "unite " << x << ' ' << y << endl;
    if(x == y)
        return false;

    p[x] = y;
    return true;
}

Node merge(Node a, Node b) {
    Node c;
    c.res = a.res + b.res;

    for(int i = 0; i < 3; i++)
        p[i] = a.lf[i];

    for(int i = 0; i < 3; i++)
        p[3 + i] = a.rg[i];

    for(int i = 0; i < 3; i++)
        p[6 + i] = (b.lf[i] == -1 ? -1 : b.lf[i] + 6);

    for(int i = 0; i < 3; i++)
        p[9 + i] = (b.rg[i] == -1 ? -1 : b.rg[i] + 6);
//    cout << "merge ";
//    for(int i = 0; i < 12; i++)
//        cout << p[i] << ' ';
//    cout << endl;
    for(int i = 0; i < 3; i++) {
        if(a.rg[i] != -1 && b.lf[i] != -1)
            c.res -= int(unite(i + 3, i + 6));
//            c.res -= unite(a.rg[i], b.lf[i]);
    }

    for(int i = 0; i < 12; i++)
        if(p[i] != -1)
            getp(i);

//    cout << "merge ";
//    for(int i = 0; i < 12; i++)
//        cout << p[i] << ' ';
//    cout << endl;

    for(int i = 0; i < 3; i++) if(a.lf[i] != -1) {
        for(int j = 0; j <= i; j++) {
            if(p[i] == p[j]) {
                c.lf[i] = j;
                break;
            }
        }
    }

    for(int i = 0; i < 3; i++) if(b.rg[i] != -1) {
        bool fl = false;
        for(int j = 0; j < 3; j++)
            if(p[j] == p[9 + i]) {
                c.rg[i] = j;
                fl = true;
                break;
            }
        if(!fl)
            for(int j = 0; j <= i; j++) {
                if(p[9 + i] == p[9 + j]) {
                    c.rg[i] = 3 + j;
                    break;
                }
            }
    }
//
//    cout << "merge ";
//    for(int i = 0; i < 12; i++)
//        cout << p[i] << ' ';
//    cout << endl;

    return c;
}

bool a[N][3];
Node t[N * 4];

void build(int v, int l, int r) {
//    cout << "build " << v << ' ' << l << ' ' << r << endl;
    if(r - l == 1) {
        if(a[l][1]) {
            t[v].res = 1;
            for(int i = 0; i < 3; i++)
                if(a[l][i])
                    t[v].lf[i] = t[v].rg[i] = 1;

        } else {
            for(int i = 0; i < 3; i++)
                if(a[l][i]) {
                    t[v].lf[i] = t[v].rg[i] = i;
                    t[v].res++;
                }
        }

        return;
    }

    int m = (l + r) / 2;

    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);

//    cout << "preend " << endl;
    t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
//    cout << "end build " << v << ' ' << l << ' ' << r << ' ' << t[v].res << endl;
//    for(int i = 0; i < 3; i++)
//        cout << t[v].lf[i] << ' ';
//    cout << endl;
//    for(int i = 0; i < 3; i++)
//        cout << t[v].rg[i] << ' ';
//    cout << endl;
}

Node get(int v, int l, int r, int ql, int qr) {
    if(ql >= r || qr <= l)
        return Node();

    if(ql <= l && r <= qr)
        return t[v];

    int m = (l + r) / 2;

    return merge(get(v * 2 + 1, l, m, ql, qr),
                 get(v * 2 + 2, m, r, ql, qr));
}

/*
2
11
10
11

3
100
110
010

7
0111111
1110010
1111110
1
1 6

7
0111111
1110010
1111110
0
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s[3];
    for(int i = 0; i < 3; i++) {
        cin >> s[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            a[i][j] = s[j][i] - '0';
        }
    }

    build(0, 0, n);

//    cout << t[0].res << endl;
    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        l--;

        cout << get(0, 0, n, l, r).res << '\n';
    }

//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();
}