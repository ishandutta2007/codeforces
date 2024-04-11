#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100005;

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

inline void cmin(int &x, int y) {
    if (x > y) x = y;
}
inline void cmax(int &x, int y) {
    if (x < y) x = y;
}

char s[MAXN][5];
int n, fst[27][27][27], lst[27][27][27];

bool solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < 27; ++i) {
        for (int j = 0; j < 27; ++j) {
            for(int k = 0; k < 27; ++k) {
                fst[i][j][k] = n + 1;
                lst[i][j][k] = 0;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        int m = strlen(s[i]);
        if (m == 1) {
            return 1;
        } else if (m == 2) {
            int a = s[i][0] - 'a', b = s[i][1] - 'a';
            if (a == b) {
                return 1;
            }
            cmin(fst[a][b][26], i);
            cmax(lst[a][b][26], i);
        } else if (m == 3) {
            int a = s[i][0] - 'a', b = s[i][1] - 'a', c = s[i][2] - 'a';
            if (a == c) {
                return 1;
            }
            cmin(fst[a][b][c], i);
            cmax(lst[a][b][c], i);
        }
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (lst[i][j][26] && lst[j][i][26]) {
                return 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        int m = strlen(s[i]);
        if (m != 3) continue;
        int a = s[i][0] - 'a', b = s[i][1] - 'a', c = s[i][2] - 'a';
        if (lst[c][b][26] && fst[c][b][26] < lst[a][b][c]) {
            return 1;
        }
        if (lst[b][a][26] && fst[a][b][c] < lst[b][a][26]) {
            return 1;
        }
        if (lst[c][b][a] && fst[a][b][c] < lst[c][b][a]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        puts(solve()? "YES" : "NO");
    }
    return 0;
}