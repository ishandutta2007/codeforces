#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int M = 998244353;
const int A = 1e6 + 13;
const int N = 1000 + 13;
//const int N = 10;
const int B = 400;
const int LOGN = 20;

mt19937 rnd(2);

int sum(int a, int b) {
    a += b;
    return (a < M ? a : a - M);
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


struct Node {
    int val;
    Node* lf = nullptr;
    Node* rg = nullptr;
    Node* up = nullptr;
    Node* dw = nullptr;

    Node() {};

    Node(int x) : val(x) {};
};

int a[N][N];
Node* p[N][N];
Node* root;

Node* get(int i, int j) {
    Node* v = root;
//    assert(root);
    for(int x = 0; x < i; x++)
        v = v->dw;
//    assert(v);
    for(int y = 0; y < j; y++)
        v = v->rg;
    return v;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            p[i][j] = new Node(a[i][j]);
            assert(p[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m - 1; j++)
            p[i][j]->rg = p[i][j + 1];
        for(int j = 1; j < m; j++)
            p[i][j]->lf = p[i][j - 1];
    }

    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n - 1; i++)
            p[i][j]->dw = p[i + 1][j];
        for(int i = 1; i < n; i++)
            p[i][j]->up = p[i - 1][j];
    }

    root = p[0][0];

    for(int i = 0; i < q; i++) {
        int x1, y1, x2, y2, h, w;
        cin >> x1 >> y1 >> x2 >> y2 >> h >> w;

        x1--;
        y1--;
        x2--;
        y2--;

        Node* v = get(x1, y1);
        Node* u = get(x2, y2);

//        cout << "sdgfg" << endl;
//        assert(v);
//        assert(u);
        for(int i = 0; i < h; i++) {
            if(v->lf)
                v->lf->rg = u;
            if(u->lf)
                u->lf->rg = v;
            swap(v->lf, u->lf);
            if(i == h - 1)
                break;
            v = v->dw;
            u = u->dw;
        }
//        assert(v);
//        assert(u);
//cout << "sdgfg" << endl;
        for(int i = 0; i < w; i++) {
            if(v->dw)
                v->dw->up = u;
            if(u->dw)
                u->dw->up = v;
            swap(v->dw, u->dw);
            if(i == w - 1)
                break;
            v = v->rg;
            u = u->rg;
        }
//cout << "sdgfg" << endl;
//        assert(v);
//        assert(u);
        for(int i = 0; i < h; i++) {
            if(v->rg)
                v->rg->lf = u;
            if(u->rg)
                u->rg->lf = v;
            swap(v->rg, u->rg);
            if(i == h - 1)
                break;
            v = v->up;
            u = u->up;
        }
//        assert(v);
//        assert(u);
//
//cout << "sdgfg" << endl;
        for(int i = 0; i < w; i++) {
            if(v->up)
                v->up->dw = u;
            if(u->up)
                u->up->dw = v;
            swap(v->up, u->up);
            if(i == w - 1)
                break;
            v = v->lf;
            u = u->lf;
        }

//        assert(v);
//        assert(u);

        if(x1 == 0 && y1 == 0)
            root = u;
        else if(x2 == 0 && y2 == 0)
            root = v;
    }

    for(int i = 0; i < n; i++) {
        Node* v = get(i, 0);

        for(int j = 0; j < m; j++) {
            cout << v->val << ' ';
            v = v->rg;
        }
        cout << endl;
    }
}