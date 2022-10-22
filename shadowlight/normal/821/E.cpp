#include <bits/stdc++.h>

#define ll long long
#define TASKNAME ""

const ll INF = 1e9 + 7;
const double EPS = 1e-8;
const int MAXN = 1e6 + 7;

using namespace std;

struct Matrix {
    int n, m;
    vector <vector <ll> > mx;
    Matrix(int n, int m) : n(n), m(m) {
        mx.resize(n, vector <ll> (m, 0));
    }
};

typedef Matrix* matrix;

matrix ones;

matrix mul(matrix a, matrix b) {
    assert(a->m == b->n);
    matrix c = new Matrix(a->n, b->m);
    for (int i = 0; i < a->n; i++) {
        for (int j = 0; j < b->m; j++) {
            for (int r = 0; r < a->m; r++) {
                c->mx[i][j] += a->mx[i][r] * b->mx[r][j];
                c->mx[i][j] %= INF;
            }
        }
    }
    return c;
}

matrix power(matrix a, ll k) {
    if (!k){
        return ones;
    }
    matrix b = power(a, k / 2);
    if (k % 2 == 0) {
        return mul(b, b);
    } else {
        return mul(b, mul(b, a));
    }
}

matrix makeOnes(int n) {
    matrix ans = new Matrix(n, n);
    for (int i = 0; i < n; i++) {
        ans->mx[i][i] = 1;
    }
    return ans;
}

matrix changeSize(matrix a, int n) {
    matrix ans = new Matrix(1, n);
    for (int i = 0; i < min(n, a->m); i++) {
        ans->mx[0][i] = a->mx[0][i];
    }
    return ans;
}

matrix getmatrix(int n) {
    matrix ans = new Matrix(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = max(0, i - 1); j <= min(n - 1, i + 1); j++) {
            ans->mx[i][j] = 1;
        }
    }
    return ans;
}

void printMatrix(matrix a) {
    for (int i = 0; i < a->n; i++) {
        for (int j = 0; j < a->m; j++) {
            cout << a->mx[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    ll n, k;
    cin >> n >> k;
    matrix now = new Matrix(1, 1);
    now->mx[0][0] = 1;
    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (b > k) {
            b = k;
        }
        c++;
        ones = makeOnes(c);
        matrix next = getmatrix(c);
        now = changeSize(now, c);
        now = mul(now, power(next, b - a));
    }
    cout << now->mx[0][0];
}