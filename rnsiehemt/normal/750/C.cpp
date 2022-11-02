#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int n;

void fail() {
    printf("Impossible\n");
    exit(0);
}

int main() {
    scanf("%d", &n);
    int l = -1e9, h = 1e9;
    for (int i = 0; i < n; i++) {
        int c, d; scanf("%d%d", &c, &d);
        if (d == 1) {
            if (h < 1900) fail();
            if (l < 1900) l = 1900;
        } else {
            if (l >= 1900) fail();
            if (h >= 1900) h = 1899;
        }
        l += c;
        h += c;
    }
    if (h >= 1e8) printf("Infinity\n");
    else printf("%d\n", h);
}