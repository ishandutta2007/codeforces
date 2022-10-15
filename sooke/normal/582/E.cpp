#include <bits/stdc++.h>

const int mod = 1e9 + 7;

inline int add(int x, int y) {
    return x + y >= mod ? x + y - mod : x + y;
}
inline int sub(int x, int y) {
    return x - y >= 0 ? x - y : x - y + mod;
}

const int N = 65536;

namespace Polynom {
    std::vector<int> operator +(std::vector<int> f, std::vector<int> g) {
        for (int i = 0; i < N; i++) { f[i] = add(f[i], g[i]); }
        return f;
    }

    void fwtand(std::vector<int> &f, int sgn) {
        for (int len = 1; len < N; len *= 2) {
            for (int i = 0; i < N; i += len * 2) {
                for (int j = 0; j < len; j++) {
                    if (sgn == 1) {
                        f[i + j] = add(f[i + j], f[i + j + len]);
                    } else {
                        f[i + j] = sub(f[i + j], f[i + j + len]);
                    }
                }
            }
        }
    }
    std::vector<int> operator &(std::vector<int> f, std::vector<int> g) {
        fwtand(f, 1); fwtand(g, 1);
        for (int i = 0; i < N; i++) { f[i] = 1ll * f[i] * g[i] % mod; }
        fwtand(f, -1);
        return f;
    }

    void fwtor(std::vector<int> &f, int sgn) {
        for (int len = 1; len < N; len *= 2) {
            for (int i = 0; i < N; i += len * 2) {
                for (int j = 0; j < len; j++) {
                    if (sgn == 1) {
                        f[i + j + len] = add(f[i + j + len], f[i + j]);
                    } else {
                        f[i + j + len] = sub(f[i + j + len], f[i + j]);
                    }
                }
            }
        }
    }
    std::vector<int> operator |(std::vector<int> f, std::vector<int> g) {
        fwtor(f, 1); fwtor(g, 1);
        for (int i = 0; i < N; i++) { f[i] = 1ll * f[i] * g[i] % mod; }
        fwtor(f, -1);
        return f;
    }
}

using Polynom::operator +;
using Polynom::operator &;
using Polynom::operator |;

int n, q, mask, cond, ans;
char str[N];
std::vector<int> res;

std::vector<int> solve(int l, int r) {
    if (l + 1 >= r) {
        std::vector<int> res(N);
        for (int x = 0; x < 4; x++) {
            if (str[l] == 'A' + x || str[l] == '?') {
                int s = 0;        
                for (int i = 0; i < 16; i++) {
                    if (str[l] == 'A' + x || str[l] == '?') {
                        s |= (i >> x & 1) << i;
                    }
                }
                res[s]++;
            }
            if (str[l] == 'a' + x || str[l] == '?') {
                int s = 0;        
                for (int i = 0; i < 16; i++) {
                    if (str[l] == 'a' + x || str[l] == '?') {
                        s |= (i >> x & 1 ^ 1) << i;
                    }
                }
                res[s]++;
            }
        }
        return res;
    }
    int d = 0, mid;
    for (int i = l; i < r; i++) {
        if (str[i] == '(') {
            d++;
        } else if (str[i] == ')') {
            d--;
        } else if (d == 0) {
            mid = i; break;
        }
    }
    std::vector<int> f = solve(l + 1, mid - 1);
    std::vector<int> g = solve(mid + 2, r - 1);
    std::vector<int> res(N);
    if (str[mid] != '|') { res = res + (f & g); }
    if (str[mid] != '&') { res = res + (f | g); }
    return res;
}

int main() {
    scanf("%s", str);
    res = solve(0, strlen(str));
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int a, b, c, d, x;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &x);
        int s = (a << 0) + (b << 1) + (c << 2) + (d << 3);
        mask |= 1 << s; cond |= x << s;
    }
    for (int s = 0; s < N; s++) {
        if ((s & mask) == cond) {
            ans = add(ans, res[s]);
        }
    }
    printf("%d\n", ans);
    return 0;
}