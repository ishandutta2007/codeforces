#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int n, a, b, c, d;
ll k;

void go(int &max, int &min, int i) {
    domax(max, i);
    domin(min, i);
}

int main() {
    scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
    for (int o = 1; o <= n; o++) {
        int max = -1e9, min = 1e9;
        go(max, min, a+b);
        go(max, min, b+d);
        go(max, min, d+c);
        go(max, min, c+a);
        k += std::max(0, n-(max-min));
    }
    printf("%lld\n", k);
}