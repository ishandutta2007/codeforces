#include <bits/stdc++.h>
using namespace std;

#define N 1010

int n, a[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int i = n; i; i --) a[i] -= a[i-1];
    vector <int> ans;
    for (int k = 1; k <= n; k ++) {
        bool fg = 1;
        for (int i = 1; i + k <= n; i ++) if (a[i] != a[i+k]) fg = 0;
        if (fg) ans.push_back(k);
    }
    int sz = ans.size();
    cout << sz << endl;
    for (int i = 0; i < sz; i ++) cout << ans[i] << ' ';
}