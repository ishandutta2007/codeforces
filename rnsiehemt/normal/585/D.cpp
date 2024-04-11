#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b > a ? (a = b, true) : false); }
typedef long long ll;

struct choice {
    int a, b, c, i;
    choice(int aa, int bb, int cc, int ii) : a(aa), b(bb), c(cc), i(ii) { }
    bool operator<(const choice &o) const {
        int k = b-a, l = c-a;
        int kk = o.b-o.a, ll = o.c-o.a;
        if (k == kk) return l < ll;
        else return k < kk;
    }
};

const int MaxN = 27;

int N, a[MaxN], b[MaxN], c[MaxN], p[20], best = -1e9, i1, i2;
std::vector<choice> v;

int f(int a, int i) {
    return (a/p[i])%3;
}

int main()
{
    p[0] = 1;
    for (int i = 0; i < 14; i++) p[i+1] = p[i] * 3;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d%d%d", &a[i], &b[i], &c[i]);

    int X = N/2, Y = N-X;
    for (int i = 0; i < p[X]; i++) {
        choice ch(0, 0, 0, i);
        for (int j = 0; j < X; j++) {
            int k = f(i, j);
            ch.a += a[j]; ch.b += b[j]; ch.c += c[j];
            if (k == 0) ch.a -= a[j];
            if (k == 1) ch.b -= b[j];
            if (k == 2) ch.c -= c[j];
        }
        v.push_back(ch);
    }

    std::sort(v.begin(), v.end());

    for (int i = 0; i < p[Y]; i++) {
        choice ch(0, 0, 0, i);
        for (int j = X; j < N; j++) {
            int k = f(i, j-X);
            ch.a += a[j]; ch.b += b[j]; ch.c += c[j];
            if (k == 0) ch.a -= a[j];
            if (k == 1) ch.b -= b[j];
            if (k == 2) ch.c -= c[j];
        }
        choice search(0, ch.a-ch.b, ch.a-ch.c, -1);
        auto resp = std::lower_bound(v.begin(), v.end(), search);
        if (resp != v.end()) {
            choice res = *resp;
            if (ch.a + res.a == ch.b + res.b && ch.b + res.b == ch.c + res.c) {
                if (domax(best, ch.a + res.a)) {
                    i1 = res.i;
                    i2 = ch.i;
                }
            }
        }
    }

    if (best == -1e9) {
        printf("Impossible\n");
    } else {
        for (int i = 0; i < X; i++) {
            int k = f(i1, i);
            if (k == 0) printf("MW\n");
            else if (k == 1) printf("LW\n");
            else printf("LM\n");
        }
        for (int i = 0; i < Y; i++) {
            int k = f(i2, i);
            if (k == 0) printf("MW\n");
            else if (k == 1) printf("LW\n");
            else printf("LM\n");
        }
    }
}