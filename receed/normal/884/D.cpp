#include <bits/stdc++.h>

using namespace std;

int main(){
#ifdef FLOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    long long t, ans = 0;
    multiset<long long> s;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &t);
        s.insert(t);
    }
    if (n % 2 == 0) {
        for (int i = 0; i < 2; i++) {
            ans += *s.begin();
            s.erase(s.begin());
        }
        s.insert(ans);
    }
    while (s.size() > 2) {
        t = 0;
        for (int i = 0; i < 3; i++) {
            t += *s.begin();
            s.erase(s.begin());
        }
        s.insert(t);
        ans += t;
    }
    printf("%lld\n", ans);

}