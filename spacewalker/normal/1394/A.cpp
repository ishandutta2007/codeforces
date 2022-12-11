#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, d, m; scanf("%d %d %d", &n, &d, &m);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    vector<ll> masMalaki, lessOrEqual;
    for (int v : arr) {
        if (v > m) masMalaki.push_back(v);
        else lessOrEqual.push_back(v);
    }
    sort(begin(masMalaki), end(masMalaki));
    sort(begin(lessOrEqual), end(lessOrEqual));
    masMalaki.push_back(0); lessOrEqual.push_back(0);
    reverse(begin(masMalaki), end(masMalaki));
    reverse(begin(lessOrEqual), end(lessOrEqual));
    for (int i = 1; i < masMalaki.size(); ++i) masMalaki[i] += masMalaki[i-1];
    for (int i = 1; i < lessOrEqual.size(); ++i) lessOrEqual[i] += lessOrEqual[i-1];
//    for (ll v : masMalaki) printf("MM %lld\n", v);
//    for (ll v : lessOrEqual) printf("LE %lld\n", v);
    ll ans = 0;
    for (ll gc = 0; gc < masMalaki.size(); ++gc) {
        ll cFodder = (int)masMalaki.size() - gc - 1;
//        printf("%d have %d fodder left\n", gc, cFodder);
        if (cFodder > gc * d) continue;
        else if (cFodder >= (gc - 1) * d) {
//            printf("just right range\n");
            ans = max(ans, masMalaki[gc] + lessOrEqual.back());
        } else {
            ll neededE = (gc - 1) * d - cFodder;
//            printf("%d need %d\n", gc, neededE);
            if ((int)lessOrEqual.size() - 1 - neededE >= 0) {
                ans = max(ans, masMalaki[gc] + lessOrEqual[(int)lessOrEqual.size() - 1 - neededE]);
            }
        }
//        printf("try %d groups ans %lld\n", gc, ans);
    }
    printf("%lld\n", ans);
}