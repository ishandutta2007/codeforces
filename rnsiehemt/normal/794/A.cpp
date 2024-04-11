#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int a, b, c, n, d, ans;

int main() {
    scanf("%d%d%d%d", &a, &b, &c, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &d);
        if (b < d && d < c) {
            ans++;
        }
    }
    printf("%d\n", ans);
}