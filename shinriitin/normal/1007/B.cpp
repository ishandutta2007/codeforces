#include <bits/stdc++.h>

const int max_N = (int) 1e5 + 21;

int t, a[3], cnt[10], f[3][4], ans[max_N], min[max_N];

bool vis[max_N], rua[8][8][8];

std::vector<int> p;

int C(int n, int m) {
    if (n < m) return 0;
    int res = 1;
    for (int i = 0; i < m; ++i) {
        res = res * (n - i) / (1 + i);
    }
    return res;
}

int main() {
    ans[1] = 1;
    for (int x = 2; x < max_N; ++x) {
        if (!vis[x]) {
            p.push_back(x);
            min[x] = 1;
            ans[x] = 2;
        }
        for (auto &y : p) {
            if (1ll * x * y >= max_N) break;
            vis[x * y] = true;
            if (x % y != 0) {
                min[x * y] = 1;
                ans[x * y] = ans[x] * 2;
            } else {
                min[x * y] = min[x] + 1;
                ans[x * y] = ans[x] / min[x * y] * (min[x * y] + 1);
                break;
            }
        }
    }

    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", a, a + 1, a + 2);

        int AB = std::__gcd(a[0], a[1]);
        int BC = std::__gcd(a[1], a[2]);
        int AC = std::__gcd(a[0], a[2]);
        int ABC = std::__gcd(a[0], BC);

        cnt[1] = ans[a[0]] - ans[AB] - ans[AC] + ans[ABC];
        cnt[2] = ans[a[1]] - ans[AB] - ans[BC] + ans[ABC];
        cnt[3] = ans[a[2]] - ans[BC] - ans[AC] + ans[ABC];
        cnt[4] = ans[AB] - ans[ABC];
        cnt[5] = ans[AC] - ans[ABC];
        cnt[6] = ans[BC] - ans[ABC];
        cnt[7] = ans[ABC];

        f[0][0] = 1;
        f[0][1] = 4;
        f[0][2] = 5;
        f[0][3] = 7;
        f[1][0] = 2;
        f[1][1] = 4;
        f[1][2] = 6;
        f[1][3] = 7;
        f[2][0] = 3;
        f[2][1] = 5;
        f[2][2] = 6;
        f[2][3] = 7;

        memset(rua, 0, sizeof(rua));

        int res = 0;

        for (int s = 0; s < (1 << 6); ++s) {
            int tmp = s;
            std::vector<int> vec;
            vec.push_back(f[0][tmp & 3]);
            tmp >>= 2;
            vec.push_back(f[1][tmp & 3]);
            tmp >>= 2;
            vec.push_back(f[2][tmp & 3]);

            std::sort(vec.begin(), vec.end());

            if (rua[vec[0]][vec[1]][vec[2]]) continue;
            rua[vec[0]][vec[1]][vec[2]] = true;

            if (vec[0] == vec[1] && vec[1] == vec[2]) {
                res += cnt[vec[0]];
                res += C(cnt[vec[0]], 2) * 2;
                res += C(cnt[vec[0]], 3);
            } else if (vec[0] == vec[1]) {
                res += cnt[vec[0]] * cnt[vec[2]];
                res += C(cnt[vec[0]], 2) * cnt[vec[2]];
            } else if (vec[1] == vec[2]) {
                res += cnt[vec[0]] * cnt[vec[1]];
                res += cnt[vec[0]] * C(cnt[vec[1]], 2);
            } else {
                res += cnt[vec[0]] * cnt[vec[1]] * cnt[vec[2]];
            }
        }

        printf("%d\n", res);
    }
    return 0;
}