#include <bits/stdc++.h>

int n, m;
std::vector<int> v[200*1000+5];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (m == 0 || a < v[m-1].back()) {
            v[m].push_back(a);
            m++;
        } else {
            int lo = 0, hi = m, best;
            while (lo <= hi) {
                int mid = (lo+hi)/2;
                if (a > v[mid].back()) {
                    best = mid;
                    hi = mid-1;
                } else {
                    lo = mid+1;
                }
            }
            v[best].push_back(a);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < int(v[i].size()); j++) {
            printf("%d%c", v[i][j], " \n"[j == int(v[i].size()) - 1]);
        }
    }
}