#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int mod = 1e9 + 7;

inline int add(int x, int y) {
    return x + y >= mod ? x + y - mod : x + y;
}
inline int sub(int x, int y) {
    return x - y >= 0 ? x - y : x - y + mod;
}
inline int power(int x, int y) {
    int res = 1;
    for (; y; y >>= 1, x = 1ll * x * x % mod) {
        if (y & 1) { res = 1ll * res * x % mod; }
    }
    return res;
}

const int N = 1e6 + 5;

int n, a[N], tms, tmp, vis[N];
std::vector<int> b;

void dfs(int i) {
    if (vis[i] == tms) { return; }
    vis[i] = tms; tmp++; dfs(a[i]);
}

int solve1() {
    int res = 1;
    if (n % 3 == 0) {
        int m = n / 3;
        for (; m; m--) { res = 3ll * res % mod; }
    } else if (n % 3 == 1) {
        int m = n / 3 - 1;
        res = 4;
        for (; m; m--) { res = 3ll * res % mod; }
    } else {
        int m = n / 3;
        res = 2;
        for (; m; m--) { res = 3ll * res % mod; }
    }
    return res;
}

int solve2() {
    int ans = 0;
    if (n % 3 == 0) {
        int c1 = 0, c2 = 0;
        for (auto x : b) {
            if (x % 3 == 0) { ans += x / 3 - 1; continue; }
            c1 += x % 3 == 1;
            c2 += x % 3 == 2;
            ans += x / 3;
        }
        ans += std::min(c1, c2);
        if (c1 > c2) {
            ans += (c1 - c2) / 3 * 2;
        } else {
            ans += c2 - c1;
        }
    } else if (n % 3 == 2) {
        int c1 = 0, c2 = 0;
        for (auto x : b) {
            if (x % 3 == 0) { ans += x / 3 - 1; continue; }
            c1 += x % 3 == 1;
            c2 += x % 3 == 2;
            ans += x / 3;
        }
        int ans1 = ans, ans2 = ans;
        if (c1 >= 2) {
            c1 -= 2; ans1++;
            ans1 += std::min(c1, c2);
            if (c1 > c2) {
                ans1 += (c1 - c2) / 3 * 2;
            } else {
                ans1 += c2 - c1;
            }
            c1 += 2;
        } else {
            ans1 = mod;
        }
        if (c2 >= 1) {
            c2 -= 1;
            ans2 += std::min(c1, c2);
            if (c1 > c2) {
                ans2 += (c1 - c2) / 3 * 2;
            } else {
                ans2 += c2 - c1;
            }
            c2 += 1;
        } else {
            ans2 = mod;
        }
        ans = std::min(ans1, ans2);
    } else {
        int c1 = 0, c2 = 0;
        bool flag = false;
        for (auto x : b) {
            if (x % 3 == 0) { ans += x / 3 - 1; continue; }
            c1 += x % 3 == 1;
            if (x % 3 == 1 && x > 1) { flag = true; }
            c2 += x % 3 == 2;
            ans += x / 3;
        }
        int ans1 = ans, ans2 = ans, ans3 = ans, ans4 = ans, ans5 = ans;
        if (c1 >= 4) {
            c1 -= 4; ans1 += 2;
            ans1 += std::min(c1, c2);
            if (c1 > c2) {
                ans1 += (c1 - c2) / 3 * 2;
            } else {
                ans1 += c2 - c1;
            }
            c1 += 4;
        } else {
            ans1 = mod;
        }
        if (c2 >= 2) {
            c2 -= 2;
            ans2 += std::min(c1, c2);
            if (c1 > c2) {
                ans2 += (c1 - c2) / 3 * 2;
            } else {
                ans2 += c2 - c1;
            }
            c2 += 2;
        } else {
            ans2 = mod;
        }
        if (c1 >= 2 && c2 >= 1) {
            c1 -= 2; c2 -= 1; ans3++;
            ans3 += std::min(c1, c2);
            if (c1 > c2) {
                ans3 += (c1 - c2) / 3 * 2;
            } else {
                ans3 += c2 - c1;
            }
            c1 += 2; c2 += 1;
        } else {
            ans3 = mod;
        }
        if (c1 == 1 && c2 == 0) {
            ans4 = ans + (flag ? -1 : 1);
        } else {
            ans4 = mod;
        }
        if (flag) {
            c1--; ans5--;
            ans5 += std::min(c1, c2);
            if (c1 > c2) {
                ans5 += (c1 - c2) / 3 * 2;
            } else {
                ans5 += c2 - c1;
            }
        } else {
            ans5 = mod;
        }
        ans = std::min(ans1, std::min(ans2, std::min(ans3, std::min(ans4, ans5))));
    }
    return ans;
}

int main() {
    for (int T = read(); T; T--) {
        n = read();
        for (int i = 1; i <= n; i++) {
            a[i] = read();
        }
        b.clear(); tms++;
        for (int i = 1; i <= n; i++) {
            if (vis[i] == tms) { continue; }
            tmp = 0; dfs(i); b.push_back(tmp);
        }
        printf("%d %d\n", solve1(), solve2());
    }
    return 0;
}