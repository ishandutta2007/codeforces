#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

struct Matrix {
    ll n, m;
    vector <vector <ll> > mat;
    Matrix(ll n, ll m) : n(n), m(m), mat(n, vector <ll> (m, 0)) {}
};

typedef Matrix* matrix;

void add(ll &x, ll y) {
    x += y;
    x %= INF;
}

matrix mul(matrix a, matrix b) {
    matrix c = new Matrix(a->n, b->m);
    assert(a->m == b->n);
    for (ll i = 0; i < a->n; i++) {
        for (ll j = 0; j < b->m; j++) {
            for (ll k = 0; k < a->m; k++) {
                add(c->mat[i][j], a->mat[i][k] * b->mat[k][j]);
            }
        }
    }
    return c;
}

matrix ones() {
    matrix a = new Matrix(3, 3);
    for (ll i = 0; i < 3; i++) {
        a->mat[i][i] = 1;
    }
    return a;
}

matrix power(matrix a, ll k) {
    if (k <= 0) {
        return ones();
    }
    matrix b = power(a, k / 2);
    b = mul(b, b);
    if (k % 2) {
        return mul(b, a);
    } else {
        return b;
    }
}

struct Seg {
    ll pos, a;
    bool open;
};

bool operator<(Seg a, Seg b) {
    if (a.pos != b.pos) {
        return a.pos < b.pos;
    }
    return a.open;
}

vector <ll> block(3, 0);

void change(matrix &a) {
    for (ll i = 0; i < 3; i++) {
        for (ll j = 0; j < 3; j++) {
            if (abs(i - j) == 2) continue;
            a->mat[i][j] = !block[i] && !block[j];
            a->mat[i][j] = !block[i] && !block[j];
        }
    }
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll n, m;
    cin >> n >> m;
    matrix sh = new Matrix(3, 3);
    change(sh);
    matrix a = new Matrix(3, 3);
    a->mat[0][1] = 1;
    vector <Seg> segs;
    for (ll i = 0; i < n; i++) {
        ll a, l, r;
        cin >> a >> l >> r;
        a--;
        segs.push_back({l, a, true});
        segs.push_back({r, a, false});
    }
    sort(segs.begin(), segs.end());
    ll pr = 1;
    for (auto t : segs) {
//        cout << t.pos << "\n";
//        for (ll i = 0; i < 3; i++) {
//            for (ll j = 0; j < 3; j++) {
//                cout << a->mat[i][j] << " ";
//            }
//            cout << "\n";
//        }
        matrix nxt = power(sh, t.pos - pr);
        a = mul(a, nxt);
//        for (ll i = 0; i < 3; i++) {
//            for (ll j = 0; j < 3; j++) {
//                cout << a->mat[i][j] << " ";
//            }
//            cout << "\n";
//        }
        pr = t.pos;
        if (t.open) {
            block[t.a]++;
        } else {
            block[t.a]--;
        }
        change(sh);
    }
    //cout << m << " " << pr << "\n";
    a = mul(a, power(sh, m - pr));
    cout << a->mat[0][1];
}