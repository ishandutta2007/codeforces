#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll INF = 1000000000000000000;

int solve() {
    int n; scanf("%d", &n);
    ll cpos = 0, ctime = 0, ctarget = 0;
    ll prevTarget = -INF;
    int ans = 0;
    auto giveCommand = [&] (ll t, ll x) {
//        printf("command %d %d when at %d time %d target %d\n", t, x, cpos, ctime, ctarget);
        ll npos = (cpos == ctarget ? cpos : (cpos < ctarget ? min(ctarget, cpos + (t - ctime)) : max(ctarget, cpos - (t - ctime))));
//        printf("moved to %d\n", npos);
        if (prevTarget != -INF && min(cpos, npos) <= prevTarget && prevTarget <= max(npos, cpos)) {
//            printf("success!\n");
            ++ans;
        }
        cpos = npos;
        ctime = t;
        prevTarget = x;
        if (cpos == ctarget) ctarget = x;
    };
    for (int i = 0; i < n; ++i) {
        int t, x; scanf("%d %d", &t, &x);
        giveCommand(t, x);
    }
    giveCommand(INF, INF); // bogus command to check if last command is successful
    return ans;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) printf("%d\n", solve());
}