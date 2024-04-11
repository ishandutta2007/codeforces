#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> p(n);
    for (int i = 1; i < n; ++i) scanf("%d", &p[i]);
    for (int i = 1; i < n; ++i) p[i] += p[i-1];
    int shift = 1 - *min_element(p.begin(), p.end());
    map<int, int> pcheck;
    for (int i = 0; i < n; ++i) {
        p[i] += shift;
        pcheck[p[i]]++;
    }
    for (auto x : pcheck) {
        if (x.second > 1 || x.first < 1 || x.first > n) {
            printf("-1\n");
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", p[i]);
    }
    return 0;
}