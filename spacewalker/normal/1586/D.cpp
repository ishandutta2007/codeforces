#include <bits/stdc++.h>

using namespace std;

int query(vector<int> s) {
    printf("?");
    for (int v : s) printf(" %d", v);
    printf("\n");
    fflush(stdout);
    int k; scanf("%d", &k);
    return k;
}

int main() {
    int n; scanf("%d", &n);
    vector<int> ans(n);
    for (int pos = 1; pos < n; ++pos) {
        vector<int> s(n, 1);
        s[n-1] += pos;
        int res = query(s);
        if (res == 0) break;
        ans[res - 1] = pos;
    }
    for (int neg = 1; neg < n; ++neg) {
        vector<int> s(n, 1);
        for (int i = 0; i < n - 1; ++i) {
            s[i] += neg; 
        }
        int res = query(s);
        if (res == 0) break;
        ans[res - 1] = -neg;
    }
    int minelem = *min_element(begin(ans), end(ans));
    for (int &v : ans) v -= minelem;
    printf("!");
    for (int v : ans) printf(" %d", v + 1);
    printf("\n");
    fflush(stdout);
}