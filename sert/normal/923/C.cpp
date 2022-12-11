#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 3e5 + 10;
const int N = 1e7 + 10;

int cur = 1;
int l[N], r[N], sum[N];
int a[M], p[M];

void add(int v, int val, int len) {
    if (len < 0) {
        sum[v]++;
        return;
    }
    if ((1 << len) & val) {
        if (r[v] == -1) {
            r[v] = cur++;
        }
        add(r[v], val, len - 1);
        sum[v]++;
    }
    else {
        if (l[v] == -1) {
            l[v] = cur++;
        }
        add(l[v], val, len - 1);
        sum[v]++;
    }
}

int get(int v, int x, int len) {
    sum[v]--;
    if (len < 0) return 0;
    if ((1 << len) & x) {
        if (r[v] != -1 && sum[r[v]] > 0) {
            return (1 << len) + get(r[v], x, len - 1);
        }
        else {
            return get(l[v], x, len - 1);
        }
    }
    else {
        if (l[v] != -1 && sum[l[v]] > 0) {
            return get(l[v], x, len - 1);
        }
        else {
            return (1 << len) + get(r[v], x, len - 1);
        }
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    scanf("%d", &n);
    fill(l, l + 30 * n + 100, -1);
    fill(r, r + 30 * n + 100, -1);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        add(0, p[i], 29);
    }

    for (int i = 0; i < n; i++) {
        cout << (get(0, a[i], 29) ^ a[i]) << " ";
    }

}