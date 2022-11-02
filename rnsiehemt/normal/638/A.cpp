#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int n, a;

int main() {
    scanf("%d%d", &n, &a);
    if (a&1) printf("%d\n", a/2+1);
    else printf("%d\n", (n-a)/2+1);
}