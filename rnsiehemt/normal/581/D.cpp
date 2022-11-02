#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
#define push_back pb
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
typedef long long ll;

int a, b, c, d, e, f;

void solve() {
    if (a == c && c == e && a == b+d+f) {
        printf("%d\n", a);
        for (int y = 0; y < b; y++) {
            for (int x = 0; x < a; x++) printf("A");
            printf("\n");
        }
        for (int y = 0; y < d; y++) {
            for (int x = 0; x < a; x++) printf("B");
            printf("\n");
        }
        for (int y = 0; y < f; y++) {
            for (int x = 0; x < a; x++) printf("C");
            printf("\n");
        }
        exit(0);
    }
    if (a == c + e && d == f && b + d == a) {
        printf("%d\n", a);
        for (int y = 0; y < b; y++) {
            for (int x = 0; x < a; x++) printf("A");
            printf("\n");
        }
        for (int y = 0; y < d; y++) {
            for (int x = 0; x < c; x++) printf("B");
            for (int x = 0; x < e; x++) printf("C");
            printf("\n");
        }
        exit(0);
    }
    if (c == a + e && b == f && b + d == c) {
        printf("%d\n", c);
        for (int y = 0; y < d; y++) {
            for (int x = 0; x < c; x++) printf("B");
            printf("\n");
        }
        for (int y = 0; y < b; y++) {
            for (int x = 0; x < a; x++) printf("A");
            for (int x = 0; x < e; x++) printf("C");
            printf("\n");
        }
        exit(0);
    }
    if (e == a + c && b == d && b + f == e) {
        printf("%d\n", e);
        for (int y = 0; y < f; y++) {
            for (int x = 0; x < e; x++) printf("C");
            printf("\n");
        }
        for (int y = 0; y < b; y++) {
            for (int x = 0; x < a; x++) printf("A");
            for (int x = 0; x < c; x++) printf("B");
            printf("\n");
        }
        exit(0);
    }
}

int main()
{
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                solve();
                std::swap(e, f);
            }
            std::swap(c, d);
        }
        std::swap(a, b);
    }
    printf("-1\n");
}