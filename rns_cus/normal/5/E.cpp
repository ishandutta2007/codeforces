#include <bits/stdc++.h>
using namespace std;

#define N 1000100

int n, a[N], le[N], ri[N];

map <int, int> mp;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &le[i]);
    int k = 0, mx = 0;
    for (int i = 1; i <= n; i ++) if (le[i] > mx) mx = le[i], k = i;
    for (int i = 1; i < n; i ++) a[i] = le[(k+i-1)%n+1];
    long long rlt = 0;
    vector <int> v;
    v.push_back(2e9);
    for (int i = 1; i < n; i ++) {
        while (v.back() < a[i]) {
            mp[v.back()] --;
            v.pop_back();
            rlt ++;
        }
        int &k = mp[a[i]];
        if (v.size() > k + 1) rlt ++;
        rlt += k;
        v.push_back(a[i]); k ++;
    }
    for (int i = 1; i < n; i ++) le[i] = max(le[i-1], a[i]);
    for (int i = n - 1; i; i --) ri[i] = max(ri[i+1], a[i]);
    for (int i = 1; i < n; i ++) if (le[i-1] <= a[i] || ri[i+1] <= a[i]) rlt ++;
    printf("%I64d\n", rlt);

    return 0;
}