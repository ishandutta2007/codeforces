#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 15;
const int M = 10004;

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

int n, m, cnt[M], ccnt[25], to[25];
LL x[N], sum[M];
char s[N][M];

inline void Count(int S) {
    mset(ccnt, 0);
    for (int i = 1; i <= m; ++i) {
        cnt[i] = 0;
        for (int j = 0; j < n; ++j) {
            if (s[j][i] == '0') continue;
            if ((S >> j) & 1) {
                --cnt[i];
            } else {
                ++cnt[i];
            }
        }
        ++ccnt[10 + cnt[i]];
    }
}

void solve() {
    read(n); read(m);
    for (int i = 0; i < n; ++i) {
        read(x[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= m; ++i) {
        sum[i] = sum[i - 1] + i;
    }
    LL ans = -1; int maxS = -1;
    for (int S = 0; S < (1 << n); ++S) {
        Count(S);
        LL cur = 0;
        for (int i = 0; i < n; ++i) {
            if ((S >> i) & 1) {
                cur += x[i];
            } else {
                cur -= x[i];
            }
        }
        int tmp = m;
        for (int i = 10 + n; i >= 10 - n; --i) {
            cur += (sum[tmp] - sum[tmp - ccnt[i]]) * (i - 10);
            tmp -= ccnt[i];
        }
        if (ans < cur) {
            ans = cur;
            maxS = S;
        }
    }
    Count(maxS);
    int tmp = m;
    for (int i = 10 + n; i >= 10 - n; --i) {
        to[i] = tmp;
        tmp -= ccnt[i];
    }
    for (int i = 1; i <= m; ++i) {
        printf("%d ", to[10 + cnt[i]]--);
    }
    printf("\n");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}