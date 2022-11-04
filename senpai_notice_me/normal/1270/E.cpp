#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 1e3 + 5;

long long sqr(long long t) {
    return t * t;
}

int n;
long long x[MAXN], y[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld%lld", x + i, y + i);
    }
    
    for (int j = 0; ; ++j) {
        vector<int> ans;
        ans.push_back(1);
        
        for (int i = 2; i <= n; ++i) {
            long long dis = sqr(x[i] - x[1]) + sqr(y[i] - y[1]);
            if ((dis >> j) % 2 == 0) {
                ans.push_back(i);
            }
        }
        
        if ((int) ans.size() < n) {
            printf("%d\n", (int) ans.size());
            for (int i = 0; i < (int) ans.size(); ++i) {
                printf("%d%c", ans[i], " \n"[i == (int) ans.size() - 1]);
            }
            break;
        }
    }
    
    return 0;
}