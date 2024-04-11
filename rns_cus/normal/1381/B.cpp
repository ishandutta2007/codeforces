#include <bits/stdc++.h>
using namespace std;

#define N 4040

int n, p[N];
bool dp[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= 2 * n; i ++) scanf("%d", &p[i]);
        vector <int> vec;
        for (int i = 1, j = 1; i <= 2 * n; i = j) {
            while (j <= 2 * n && p[j] <= p[i]) j ++;
            vec.push_back(j - i);
        }
        for (int i = 0; i <= n; i ++) dp[i] = 0;
        dp[0] = 1;
        for (auto x : vec) {
            for (int i = n - x; i >= 0; i --) if (dp[i]) dp[i+x] = 1;
        }
        if (dp[n]) puts("YES");
        else puts("NO");
    }

    return 0;
}