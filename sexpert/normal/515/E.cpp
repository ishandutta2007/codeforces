#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<ll, 2> ar;
typedef array<ar, 2> obj;
const ll INF = 1e18;
const int MAXN = 2e5 + 10;
ll f1[MAXN], f2[MAXN], pre[MAXN], d[MAXN], h[MAXN];

obj merge(obj a, obj b) {
    if(a[1][0] > b[0][0])
        return a;
    if(b[1][0] > a[0][0])
        return b;
    obj res;
    res[0] = a[0];
    res[1] = b[0];
    if(res[0][0] < res[1][0])
        swap(res[0], res[1]);
    return res;
}

struct node {
    int l, r;
    obj v;
    node *left, *right;

    node(int l, int r, ll *A) : l(l), r(r) {
        if(l == r) {
            v[0] = {A[l], l};
            v[1] = {-INF, -1};
        }
        else {
            int m = (l + r)/2;
            left = new node(l, m, A);
            right = new node(m + 1, r, A);
            v = merge(left->v, right->v);
        }
    }

    obj qry(int rl, int rr) {
        if(rr < l || r < rl) {
            obj res;
            res[0] = res[1] = {-INF, -1};
            return res;
        }
        if(rl <= l && r <= rr)
            return v;
        return merge(left->qry(rl, rr), right->qry(rl, rr));
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 2; i <= n + 1; i++)
        cin >> d[i];
    for(int i = 1; i <= n; i++)
        cin >> h[i];
    for(int i = n + 1; i <= 2*n; i++)
        h[i] = h[i - n];
    for(int i = n + 2; i <= 2*n; i++)
        d[i] = d[i - n];
    for(int i = 2; i <= 2*n; i++)
        pre[i] = pre[i - 1] + d[i];
    for(int i = 1; i <= 2*n; i++) {
        f1[i] = 2 * h[i] + pre[i];
        f2[i] = 2 * h[i] - pre[i];
    }
    node t1(1, 2*n, f1), t2(1, 2*n, f2);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        obj a1, a2;
        if(a <= b) {
            a1 = t1.qry(b + 1, a + n - 1);
            a2 = t2.qry(b + 1, a + n - 1);
        }
        else {
            a1 = t1.qry(b + 1, a - 1);
            a2 = t2.qry(b + 1, a - 1);
        }
        if(a1[0][1] != a2[0][1])
            cout << a1[0][0] + a2[0][0] << '\n';
        else 
            cout << max(a1[0][0] + a2[1][0], a2[0][0] + a1[1][0]) << '\n';
    }
}