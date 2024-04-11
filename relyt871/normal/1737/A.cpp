#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 200005;

template <typename T> inline void read(T &WOW) {
    T x = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') flag = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    WOW = flag * x;
}

char s[MAXN];
int n, k, cnt[26];

void solve() {
    read(n); read(k);
    scanf("%s", s + 1);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; ++i) {
        ++cnt[s[i] - 'a'];
    }
    for (int i = 1; i <= k; ++i){
        int p = 0;
        while (p < (n / k) && cnt[p]) {
            --cnt[p];
            ++p;
        }
        putchar(p + 'a');
    }
    puts("");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}