#include <bits/stdc++.h>
using namespace std;

#define N 1000100

int n, m;
string s[N];
vector <bool> x[N], y[N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i ++) cin >> s[i], x[i].assign(m, 0), y[i].assign(m, 0);
    x[0][0] = 1;
    for (int k = 1; k < n + m - 1; k ++) {
        for (int i = max(0, k - m + 1); i <= min(n - 1, k); i ++) {
            int j = k - i;
            if (s[i][j] != '.') continue;
            if (i > 0 && s[i-1][j] == '.' && x[i-1][j]) x[i][j] = 1;
            if (j > 0 && s[i][j-1] == '.' && x[i][j-1]) x[i][j] = 1;
        }
    }
    y[n-1][m-1] = 1;
    for (int k = n + m - 3; k >= 0; k --) {
        for (int i = max(0, k - m + 1); i <= min(n - 1, k); i ++) {
            int j = k - i;
            if (s[i][j] != '.') continue;
            if (i < n - 1 && s[i+1][j] == '.' && y[i+1][j]) y[i][j] = 1;
            if (j < m - 1 && s[i][j+1] == '.' && y[i][j+1]) y[i][j] = 1;
        }
    }
    if (!x[n-1][m-1]) puts("0");
    else {
        for (int k = 1; k < n + m - 2; k ++) {
            int cnt = 0;
            for (int i = max(0, k - m + 1); i <= min(n - 1, k); i ++) {
                int j = k - i;
                if (x[i][j] && y[i][j]) cnt ++;
            }
            assert(cnt > 0);
            if (cnt == 1) return puts("1"), 0;
        }
        puts("2");
    }

    return 0;
}