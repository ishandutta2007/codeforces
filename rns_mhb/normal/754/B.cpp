#include <bits/stdc++.h>
using namespace std;

#define N 10

int n, ans;
char s[N][N];
char t[N][N];

int mx[] = {0, -1, -1, -1};
int my[] = {1, 1, 0, -1};

bool in(int x) {
    return x < n && x >= 0;
}

bool test(int x, int y) {
    for (int i = 0; i < n; i ++)
    for (int j = 0; j < n; j ++) {
        if (i == x && j == y) t[i][j] = 'x';
        else t[i][j] = s[i][j];
    }
    for (int i = 0; i < n; i ++)
    for (int j = 0; j < n; j ++) if (t[i][j] == 'x') {
        for (int a = 0; a < n; a ++) {
            if (in(i + mx[a]) && in(j + my[a]) && t[i+mx[a]][j+my[a]] == 'x' &&
            in(i + mx[a] * 2) && in(j + my[a] * 2) && t[i+mx[a]*2][j+my[a]*2] == 'x') return 1;
        }
    }
    return 0;
}

int main() {
    n = 4;
    for (int i = 0; i < n; i ++) gets(s[i]);
    for (int i = 0; i < n; i ++)
    for (int j = 0; j < n; j ++) if (s[i][j] == '.') {
        if (test(i, j)) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}