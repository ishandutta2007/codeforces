#include <bits/stdc++.h>
using namespace std;

#define N 1010

int n, a[N];
bool vis[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
        vector <int> ans;
        while (1) {
            for (int i = 0; i <= n; i ++) vis[i] = 0;
            for (int i = 1; i <= n; i ++) vis[a[i]] = 1;
            int k;
            for (k = 0; k <= n; k ++) if (!vis[k]) break;
            if (k < n) {
                ans.push_back(k + 1);
                a[k+1] = k;
            }
            else {
                for (k = 0; k < n; k ++) if (a[k+1] != k) break;
                if (k >= n) break;
                int c = a[k+1];
                ans.push_back(k + 1), a[k+1] = n;
                ans.push_back(c + 1), a[c+1] = c;
            }
        }
        int sz = ans.size();
        printf("%d\n", sz);
        for (int i = 0; i < sz; i ++) printf("%d ", ans[i]); puts("");
    }

    return 0;
}