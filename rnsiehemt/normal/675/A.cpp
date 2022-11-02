#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int a, b, c;

int main() {
    scanf("%d%d%d", &a, &b, &c);
    b -= a;
    if (c == 0) {
        if (b == 0) printf("YES\n");
        else printf("NO\n");
    } else {
        if ((b/c)*c == b && b/c >= 0) printf("YES\n");
        else printf("NO\n");
    }
}