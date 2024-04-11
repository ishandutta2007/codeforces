#include <bits/stdc++.h>

using namespace std;


int main(){
#ifdef FLOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    vector<int> used(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    vector<long long> l;
    for (int i = 1; i <= n; i++) {
        if (used[i])
            continue;
        long long x = 0;
        for (int j = i; !used[j]; j = p[j]) {
            used[j] = 1;
            x++;
        }
        l.push_back(x);
    }
    if (l.size() == 1) {
        printf("%lld", l[0] * l[0]);
        return 0;
    }
    sort(l.begin(), l.end());
    long long ans = l.back() + l[l.size() - 2];
    ans *= ans;
    for (int i = 0; i < l.size() - 2; i++)
        ans += l[i] * l[i];
    printf("%lld\n", ans);
}