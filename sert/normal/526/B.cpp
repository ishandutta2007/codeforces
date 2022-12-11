#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 34;

string s;
int n;
int a[N], ans[N];
int res;

int go(int v, int lv) {
    if (lv == 0) return 0;
    int a1 = go(v * 2, lv - 1) + a[v * 2];
    int a2 = go(v * 2 + 1, lv - 1) + a[v * 2 + 1];
    res += abs(a1 - a2);
    return max(a1, a2);
}

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n;
    for (int i = 2; i < (1 << (n + 1)); i++) cin >> a[i];
    go(1, n);
    cout << res;
    return 0;
}