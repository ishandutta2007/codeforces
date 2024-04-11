#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int i = 0, t = 4*60 - k;
    while (t - 5*(i+1) >= 0) {
        t -= 5*(i+1);
        i++;
    }
    i = std::min(i, n);
    printf("%d\n", i);
}