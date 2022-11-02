#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int w[3], n[3], m;

int main() {
    scanf("%d", &m);
    w[0] = 0;
    w[1] = 0;
    w[2] = 0;
    for (int i = 0; i < m; i++) {
        int a;
        scanf("%d", &a);
        n[0] = std::min(std::min(w[0], w[1]), w[2]) + 1;
        if (a == 2 || a == 3) {
            n[1] = std::min(w[0], w[2]);
        } else n[1] = 1e9;
        if (a == 1 || a == 3) {
            n[2] = std::min(w[0], w[1]);
        } else n[2] = 1e9;
        w[0] = n[0];
        w[1] = n[1];
        w[2] = n[2];
    }
    printf("%d\n", std::min(w[0], std::min(w[1], w[2])));
}