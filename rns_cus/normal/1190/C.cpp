#include <bits/stdc++.h>
using namespace std;

#define N 100100
int n, k, cnt[N];
char s[N];

int main() {
    scanf("%d %d", &n, &k);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i ++) cnt[i] = cnt[i-1] + (s[i] == '1');
    for (int i = 1; i <= n - k + 1; i ++) {
        if (cnt[i-1] == i - 1 && cnt[i+k-1] == cnt[n] - (n - i - k + 1)) return puts("tokitsukaze"), 0;
        if (cnt[i-1] == 0 && cnt[i+k-1] == cnt[n]) return puts("tokitsukaze"), 0;
    }
    bool fg = 1;
    vector <int> vec;
    for (int i = 1; i <= n; i ++) if (s[i] == '0') vec.push_back(i);
    if (vec.back() - vec.front() >= k + 1) fg = 0;
    int sz = vec.size(), i = 0;
    while (i < sz && vec[i] <= k) i ++;
    if (i < sz && vec.back() - vec[i] >= k) fg = 0;
    i = sz - 1;
    while (i >= 0 && vec[i] >= n - k + 1) i --;
    if (i >= 0 && vec[i] - vec.front() >= k) fg = 0;
    vec.clear();
    for (int i = 1; i <= n; i ++) if (s[i] == '1') vec.push_back(i);
    if (vec.back() - vec.front() >= k + 1) fg = 0;
    sz = vec.size(), i = 0;
    while (i < sz && vec[i] <= k) i ++;
    if (i < sz && vec.back() - vec[i] >= k) fg = 0;
    i = sz - 1;
    while (i >= 0 && vec[i] >= n - k + 1) i --;
    if (i >= 0 && vec[i] - vec.front() >= k) fg = 0;
    if (fg) puts("quailty");
    else puts("once again");

    return 0;
}