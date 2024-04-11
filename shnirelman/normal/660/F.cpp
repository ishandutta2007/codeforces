#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 2e5 + 113;
const int K = 1e5 + 113;
const int M = 1e9 + 7;
const int A = 26;

/*
*/

struct Func {
    li k, b;

    Func() : k(0ll), b(-INF64) {};

    Func(li k, li b) : k(k), b(b) {};

    li operator()(li x) {
        return x * k + b;
    }
};

struct Node {
    Func f;

    Node* lf;
    Node* rg;

    Node() : f(), lf(nullptr), rg(nullptr) {};

    Node(Func f) : f(f), lf(nullptr), rg(nullptr) {};
};

Node* add(Node* v, li l, li r, Func f) {
//    cout << "add " << l << ' ' << r << "  " << v->f.k << ' ' << v->f.b << " | " << f.k << ' ' << f.b << endl;
    if(!v) {
        return new Node(f);
    }

//    cout << "add " << l << ' ' << r << "  " << v->f.k << ' ' << v->f.b << " | " << f.k << ' ' << f.b << endl;
//cout << "add " << l << ' ' << r << endl;
    li m = (l + r) / 2;

    if(v->f(m) < f(m)) {
        swap(v->f, f);
    }

    if(r - l == 1)
        return v;

    if(v->f(l) < f(l))
        v->lf = add(v->lf, l, m, f);
    else
        v->rg = add(v->rg, m, r, f);

    return v;
}

li get(Node* v, li l, li r, li x) {
    if(!v)
        return -INF64;

    if(r - l == 1)
        return v->f(x);

    li m = (l + r) / 2;

    if(x < m)
        return max(v->f(x), get(v->lf, l, m, x));
    else
        return max(v->f(x), get(v->rg, m, r, x));
}

int n;
int a[N];

li s[N], p[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    s[0] = p[0] = 0;
    for(int i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i];
        p[i + 1] = p[i] + a[i] * 1ll * (i + 1);
    }

    li L = -li(1e12) + 100;
    li R = -L;

    Node*  root = nullptr;
//    cout << "vsadv" << endl;
    root = add(root, L, R, Func(0ll, 0ll));

    li ans = 0;

    for(int i = 1; i <= n; i++) {
//        cout << i << ' ' << p[i] << ' ' << s[i] << ' ' << get(root, -INF64, INF64, s[i]) << ' ' << p[i] + get(root, -INF64, INF64, s[i]) << endl;
        ans = max(ans, p[i] + get(root, L, R, s[i]));

        root = add(root, L, R, Func(-i, s[i] * i - p[i]));
//        cout << "for add k=" << -i << " b=" << s[i] * i - p[i] << endl;
    }

    cout << ans << endl;
}