#include <bits/stdc++.h>

const int N = 3e6 + 5;

int T, n, _n, ans, ansl, ansr, p[N], lp[N], rp[N];
char str[N], s[N];
bool visl[N], visr[N];

void manacher() {
    int mid = 0, max = 0;
    for (int i = 1; i <= n; i++) {
        if (i < max) {
            p[i] = std::min(p[mid * 2 - i], max - i);
        } else {
            p[i] = 1;
        }
        for (; str[i - p[i]] == str[i + p[i]]; p[i]++);
        if (max < i + p[i]) {
            max = i + p[i]; mid = i;
        }
    }
}

int main() {
    for (scanf("%d", &T); T; T--) {
        scanf("%s", s); _n = strlen(s);
        str[n] = str[n + 1] = str[n + 2] = ' '; n = 0;
        str[++n] = '~';
        for (int i = 0; i < _n; i++) {
            str[++n] = s[i];
            str[++n] = '#';
        }
        str[n] = '!';
        manacher();
        for (int i = 0; i <= _n; i++) { visl[i] = visr[i] = false; }
        bool flag = false;
        int par = 0;
        for (int i = 0, j = _n - 1; ; ) {
            if (s[i] == s[j]) {
                visl[i] = visr[j] = true;
                i++; j--;
                par++;
                if (i > j) { flag = true; break; }
            } else {
                break;
            }
        }
        if (flag) {
            for (int i = 0; i < _n; i++) { putchar(s[i]); }
            printf("\n");
            continue;
        }
        ans = 1; ansl = 1; ansr = n - 1;
        for (int i = 2; i <= n; i++) {
            p[i]--;
            if (str[i + p[i]] == '#') {
                if (p[i] == 0) { continue; }
                p[i]--;
            }
            int l = (i - p[i]) / 2 - 1, r = (i + p[i]) / 2 - 1;
            int len = std::min(l, _n - 1 - r);
            if (len <= par) {
                int det = r - l + 1;
                if (ans < det + len + len) {
                    ans = det + len + len;
                    if (len == l) {
                        ansl = r + 1;
                        ansr = _n - 1 - len;
                    } else {
                        ansl = len;
                        ansr = l - 1;
                    }
                }
            }
        }
        for (int i = 0; i < ansl; i++) { putchar(s[i]); }
        for (int i = ansr + 1; i < _n; i++) { putchar(s[i]); }
        printf("\n");
    }
    return 0;
}