#include <bits/stdc++.h>
using namespace std;

#define N 4040

int n;
char s[N], t[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%s %s", s + 1, t + 1);
        n = strlen(s + 1);
        int x = 0, y = 0;
        for (int i = 1; i <= n; i += 2) {
            if (s[i] == '0' && s[i+1] == '0') x ++;
            if (s[i] == '1' && s[i+1] == '1') y ++;
            if (t[i] == '0' && t[i+1] == '0') x --;
            if (t[i] == '1' && t[i+1] == '1') y --;
        }
        if (x || y) {puts("-1"); continue;}
        bool rev = 0, fg = 0;
        int a = 0, b = 0, c = 0, d = 0;
        for (int i = 1; i <= n; i += 2) {
            if (s[i] == '0' && s[i+1] == '1') a ++;
            if (s[i] == '1' && s[i+1] == '0') b ++;
            if (t[i] == '0' && t[i+1] == '1') c ++;
            if (t[i] == '1' && t[i+1] == '0') d ++;
        }
        if (min(a, b) > min(c, d)) rev = 1, swap(s, t), swap(a, c), swap(b, d);
        vector <int> ans;
        if (a > b) swap(a, b), swap(c, d), fg = 1;
        if (b != c) {
            int cnt = 0, k;
            for (k = 2; k <= n; k += 2) {
                if (s[k-1] == '0' && s[k] == '1') {
                    if (fg) cnt ++;
                    else cnt --;
                }
                if (s[k-1] == '1' && s[k] == '0') {
                    if (fg) cnt --;
                    else cnt ++;
                }
                if (cnt == b - c) break;
            }
            if (k > n) while (1);
            ans.push_back(k);
            reverse(s + 1, s + k + 1);
        }
        for (int i = 2; i <= n; i += 2) {
            int k;
            for (k = i; k <= n; k += 2) if (s[k] == t[n-i+1] && s[k-1] == t[n-i+2]) break;
            assert(k <= n);
            if (k > 2) {
                ans.push_back(k - 2);
                reverse(s + 1, s + k - 1);
            }
            ans.push_back(k);
            reverse(s + 1, s + k + 1);
        }
        if (rev) reverse(ans.begin(), ans.end());
        int sz = ans.size();
        printf("%d\n", sz);
        for (int i = 0; i < sz; i ++) printf("%d%c", ans[i], " \n"[i==sz-1]);
    }
}