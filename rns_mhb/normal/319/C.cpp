#include<bits/stdc++.h>
using namespace std;
#define N 100010

int n, a[N], b[N];
#define ll long long
ll f[N];
int id[N];
ll func(int x, int i) {
    return 1ll * x * b[i] + f[i];
}

double cross(int i, int j) {
    return 1.0 * (f[i] - f[j]) / (b[j] - b[i]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++) scanf("%d", &b[i]);
    f[1] = 0;
    int st = 1, en = 0;
    for (int i = 1; i <= n; i ++) {
        while (st < en && func(a[i], id[st]) >= func(a[i], id[st+1])) st ++;
        f[i] = func(a[i], id[st]);
        while (st < en && cross(id[en], id[en - 1]) >= cross(id[en], i)) en --;
        id[++en] = i;
    }
    cout<<f[n]<<endl;
}