#include <bits/stdc++.h>
using namespace std;
 
#define N 100100
 
int id[300], x[N], fst[30], lst[30], cnt[30];
int n, a, b;
bool dp[1<<20];
char ch[30], s[N];
 
inline bool good(int y) {
    int l = n, r = 0, tot = 0;
    for (int i = 0; i < 20; i ++) if (y >> i & 1) {
        if (cnt[i]) {
            tot += cnt[i];
            l = min(l, fst[i]);
            r = max(r, lst[i]);
        }
    }
    return (r - l + 1) * a <= b * tot;
}
 
int main() {
    for (int i = 'a', j = 0; i <= 'z'; i ++) {
        if (i == 't' || i == 'r' || i == 'y' || i == 'u' || i == 'b' || i == 'g') continue;
        id[i] = j, ch[j] = i; j ++;
    }
    scanf("%d %d %d", &n, &a, &b);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i ++) x[i] = id[s[i]];
    for (int i = 1; i <= n; i ++) {
        if (!fst[x[i]]) fst[x[i]] = i;
        lst[x[i]] = i;
        cnt[x[i]] ++;
    }
    int up = 1 << 20;
    dp[0] = 1;
    for (int i = 1; i < up; i ++) {
        if (good(i)) {
            for (int j = 0; j < 20; j ++) if (i >> j & 1) {
                if (dp[i^1<<j]) dp[i] = 1;
            }
        }
        if (dp[i]) continue;
        vector <int> vec;
        for (int j = 0; j < 20; j ++) if (i >> j & 1) {
            vec.push_back(j);
        }
        sort(vec.begin(), vec.end(), [&](int x, int y) {return fst[x] < fst[y];});
        int prv = 0;
        for (auto x : vec) {
            if (dp[prv] && dp[i^prv]) {
                dp[i] = 1;
                break;
            }
            prv ^= 1 << x;
        }
    }
    vector <int> ans;
    for (int i = 0; i < 20; i ++) if (cnt[i] && dp[up-1^1<<i]) ans.push_back(i);
    printf("%d", ans.size());
    for (auto x : ans) printf(" %c", ch[x]); puts("");
 
    return 0;
}