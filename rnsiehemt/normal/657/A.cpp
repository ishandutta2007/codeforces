#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int n, d, h;

int main() {
    scanf("%d%d%d", &n, &d, &h);
    if (d > h*2) printf("-1\n");
    else if (h == 1 && d == 1 && n > 2) printf("-1\n");
    else {
        for (int i = 2; i <= h+1; i++) printf("%d %d\n", i-1, i);
        int k = 1;
        if (d == h) k = 2;
        if (h+2 <= n) printf("%d %d\n", k, h+2);
        for (int i = h+3; i <= d+1; i++) printf("%d %d\n", i-1, i);
        for (int i = std::max(h+3, d+2); i <= n; i++) printf("%d %d\n", k, i);
    }
}