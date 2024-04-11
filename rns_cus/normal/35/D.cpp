#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, x;
    vector <int> v;
    scanf("%d %d", &n, &x);
    for (int i = 0, c; i < n; i ++) {
        scanf("%d", &c);
        v.push_back(c * (n - i));
    }
    sort(v.begin(), v.end());
    int k, s = 0, sz = v.size();
    for (k = 0; k < sz; k ++) {
        s += v[k];
        if (s > x) break;
    }
    printf("%d\n", k);

    return 0;
}