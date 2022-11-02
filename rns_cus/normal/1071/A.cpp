#include <bits/stdc++.h>
using namespace std;

#define N 100100

int a, b;
int t, vis[N];
vector <int> ans1, ans2;

void solve(int k, int a) {
    if (k == 0) return;
    if (k < a) vis[k] = 1, solve(k - 1, a - k);
    else vis[a] = 1;
}

void print(vector <int> v) {
    int sz = v.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; i ++) printf("%d ", v[i]); puts("");
}

int main() {
    scanf("%d %d", &a, &b);
    t = 1;
    while (1ll * t * (t + 1) / 2 <= a + b) t ++;
    solve(t - 1, a);
    for (int i = 1; i < t; i ++) {
        if (vis[i]) ans1.push_back(i);
        else ans2.push_back(i);
    }
    print(ans1), print(ans2);

    return 0;
}