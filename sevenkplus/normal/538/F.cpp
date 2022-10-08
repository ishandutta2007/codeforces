#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 200010

int n, a[N]; int p[N], L;

struct T {
    T *l, *r;
    int s;
    
    T(T *l_ = NULL, T *r_ = NULL, int s_ = 0) {l = l_; r = r_; s = s_;}
};

T* f[N];

T* add(T* p, int l, int r, int x) {
    if (l == r-1) return new T(NULL, NULL, p->s+1);
    int mid = (l+r)/2;
    T *lt = p->l, *rt = p->r;
    if (lt == NULL) lt = new T();
    if (rt == NULL) rt = new T();
    if (x < mid) lt = add(lt, l, mid, x);
    else rt = add(rt, mid, r, x);
    return new T(lt, rt, lt->s+rt->s);
}

int ask(T* p, int l, int r, int L, int R) {
    if (p == NULL) return 0;
    if (L <= l && r <= R) return p->s;
    int mid = (l+r)/2, S = 0;
    if (L < mid) S += ask(p->l, l, mid, L, R);
    if (mid < R) S += ask(p->r, mid, r, L, R);
    return S;
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        p[L++] = a[i];
    }
    sort(p, p+L);
    L = unique(p, p+L) - p;

    f[0] = new T();
    for (int i = 0; i < n; i ++) {
        a[i] = lower_bound(p, p+L, a[i]) - p;
        f[i+1] = add(f[i], 0, L, a[i]);
    }
    
    for (int k = 1; k <= n-1; k ++) {
        int S = 0;
        for (int i = 0; i < n; i ++) {
            if (k*i+1 >= n) break;
            int le = k*i+1, ri = min(n, k*i+k+1);
            S += ask(f[ri], 0, L, 0, a[i]) - ask(f[le], 0, L, 0, a[i]);
        }
        printf ("%d%c", S, k == n-1?'\n': ' ');
    }
    return 0; 
}