#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int n, p = 20*1000;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x; char d;
        scanf("%d %c%*s", &x, &d);
        if (d == 'W' || d == 'E') {
            x = 0;
            if (p == 0 || p == 20*1000) {
                printf("NO\n");
                return 0;
            }
        }
        else if (d == 'S') x = -x;
        p += x;
        if (p < 0 || p > 20*1000) {
            printf("NO\n");
            return 0;
        }
    }
    if (p != 20*1000) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
}