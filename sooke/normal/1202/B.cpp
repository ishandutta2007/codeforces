#include <bits/stdc++.h>

int dis[10][10];

std::string s;

int solve(int x, int y) {
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) { dis[i][j] = 1e9; }
    }
    for (int i = 0; i <= 9; i++) {
        dis[i][(i + x) % 10] = dis[i][(i + y) % 10] = 1;
    }
    for (int k = 0; k <= 9; k++) {  
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    int res = 0;
    for (int i = 1; i < s.size(); i++) {
        int x = dis[s[i - 1] & 15][s[i] & 15];
        if (x > 1e3) { return -1; }
        res += x - 1;
    }
    return res;
}

int main() {
    std::cin >> s;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            printf("%d ", solve(i, j));
        }
        printf("\n");
    }
    return 0;
}