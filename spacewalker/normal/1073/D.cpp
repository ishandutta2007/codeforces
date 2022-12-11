#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n; ll t; scanf("%d %lld", &n, &t);
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
    vector<int> nxt(n), prev(n);
    for (int i = 0; i < n; ++i) nxt[i] = (i + 1) % n;
    for (int i = 0; i < n; ++i) prev[nxt[i]] = i;
    ll ans = 0;
    int dead = 0, cloc = 0;
    ll streakSum = 0, streakCount = 0;
    while (dead < n) {
//        printf("at %d with %lld\n", cloc, t);
        if (arr[cloc] > t) { // kill this
//            printf("%d dead\n", cloc);
            streakCount = 0;
            streakSum = 0;
            ++dead;
            if (dead == n) break;
            int tlp = prev[cloc], tln = nxt[cloc];
            nxt[tlp] = tln; prev[tln] = tlp;
            cloc = tln;
        } else { // buy this
            if (streakCount + dead == n) {
//                printf("TIME TRAVEL FORWARD; skipping %lld rounds\n", max(0LL, (t/streakSum - 1)));
                int alive = n - dead;
                // bring t to within [streakSum, streakSum * 2)
                if (t >= streakSum) {
                    ans += alive * (t / streakSum - 1);
                    t = streakSum + t % streakSum;
                }
                streakSum = 0;
                streakCount = 0;
            } else { 
//                printf("buying %d\n", cloc);
                ++ans;
                streakCount++;
                streakSum += arr[cloc];
                t -= arr[cloc];
                cloc = nxt[cloc]; 
            }
        }
    }
    printf("%lld\n", ans);
}