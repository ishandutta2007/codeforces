#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-6;

#define N 100010

int w, a[N], b[N], c[N], x[N], v[N];

double L(int i) {
    return 1.0 * (v[i]-w-eps)/x[i];
}

double R(int i) {
    return 1.0 * (v[i]+w+eps)/x[i];
}

bool cmpa(int i, int j) {
    return L(i) < L(j);
}

bool cmpb(int i, int j) {
    return R(i) < R(j);
}

int f[N];

void add(int x) {
    for(; x < N; x += x & -x) f[x] ++;
}

int query(int x) {
    int r = 0;
    for(; x; x &= x - 1) r += f[x];
    return r;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n >> w;
    for(int i = 1; i <= n; i ++) cin >> x[i] >> v[i];
    for(int i = 1; i <= n; i ++) a[i] = b[i] = i;
    sort(a+1, a+n+1, cmpa);
    sort(b+1, b+n+1, cmpb);
    for(int i = 1; i <= n; i ++) c[a[i]] = i;
    for(int i = 1; i <= n; i ++) b[i] = c[b[i]];
    long long ans = 0;
    for(int i = n; i; i --) {
        ans += query(b[i]);
        add(b[i]);
    }
    cout << ans << endl;
}