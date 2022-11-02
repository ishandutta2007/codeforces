#include <bits/stdc++.h>
using namespace std;

#define N 1010

int n, a[N];
typedef pair <int, int> pii;
vector <pii> ans;

void solve(vector <int> &vec) {
    int sz = vec.size();
    if (sz < 2) return;
    int mx = 0, k;
    for (int i = 0; i < sz; i ++) {
        int x = vec[i];
        if (a[x] >= mx) mx = a[x], k = i;
    }
    vector <int> v;
    for (int i = 0; i < sz; i ++) if (i != k) v.push_back(vec[i]);
    solve(v);
    for (int i = sz - 1; i > k; i --) ans.emplace_back(vec[k], vec[i]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    vector <int> vec; ans.clear();
    for (int i = 1; i <= n; i ++) vec.push_back(i);
    solve(vec);
    int sz = ans.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; i ++) printf("%d %d\n", ans[i].first, ans[i].second);

    return 0;
}