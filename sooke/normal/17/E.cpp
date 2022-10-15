#include <cstdio>
#include <algorithm>

const int mod = 51123987;

inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int sub(int x, int y) { return x - y >= 0 ? x - y : x - y + mod; }

const int N = 4e6 + 5;

int n, _n, ans, pal[N], pre[N], suf[N];
char str[N], _str[N];

void manacher() {
    int mid, max = 0;
    for (int i = 1; i < n; i++) {
        if (i < max) {
            pal[i] = std::min(pal[mid * 2 - i], max - i);
        } else {
            pal[i] = 1;
        }
        for (; str[i - pal[i]] == str[i + pal[i]]; pal[i]++);
        if (max < i + pal[i]) {
            max = i + pal[i]; mid = i;
        }
    }
}

int main() {
    scanf("%d%s", &_n, _str); str[n++] = '~';
    for (int i = 0; i < _n; i++) {
        str[n++] = '#'; str[n++] = _str[i];
    } str[n++] = '#'; manacher();
    for (int i = 1; i < n; i++) {
        ans = add(ans, pal[i] / 2);
        pre[i + pal[i]]--; pre[i]++;
        suf[i - pal[i]]--; suf[i]++;
    }ans = 1ll * ans * (ans - 1) / 2 % mod;
    for (int i = 1; i < n; i++) { pre[i] += pre[i - 1]; }
    for (int i = n; i > 0; i--) { suf[i - 1] += suf[i]; }
    for (int i = 1; i < n; i++) {
        pre[i]--; suf[i]--;
        if (str[i] != '#') { pre[i] = suf[i] = 0; }
    }
    for (int i = 1; i < n; i++) { pre[i] = add(pre[i], pre[i - 1]); }
    for (int i = 1; i < n; i++) {
        if (str[i] == '#') { ans = sub(ans, 1ll * pre[i] * suf[i] % mod); }
    }
    printf("%d\n", ans);
    return 0;
}