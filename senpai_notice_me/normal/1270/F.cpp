#include <bits/stdc++.h>

#define __advance __attribute__((optimize("O3")))

using namespace std;

const int MAXN = (int) 2e5 + 5;

int n;
char s[MAXN];

int one_cnt[MAXN];

int prev_one[MAXN];

unordered_map<int, int> cnt;

__advance int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    
    int prev = 0;
    
    for (int i = 1; i <= n; ++i) {
        prev_one[i] = prev;
        if (s[i] == '1') {
            prev = i;
        }
        one_cnt[i] = one_cnt[i - 1] + (s[i] == '1');
    }
    
    int sqrt_n = min(n, 350);
    
    long long ans = 0;
    
    for (register int k = 1; k <= sqrt_n; ++k) {
        cnt.clear();
        cnt[0] = 1;
        
        for (register int i = 1; i <= n; ++i) {
            ans += cnt[i - k * one_cnt[i]];
            cnt[i - k * one_cnt[i]] += 1;
        }
    }
    
    for (register int i = 1; i <= n; ++i) {
        register int now = (s[i] == '1' ? i : prev_one[i]);
        register int now_one = 1;
        while (now > 0 && now_one * (sqrt_n + 1) <= i) {
            prev = prev_one[now];
            
            int tmp = (i - prev) / now_one - max((i - now) / now_one, sqrt_n);
            
            ans += max(tmp, 0);

            now = prev;
            now_one += 1;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}