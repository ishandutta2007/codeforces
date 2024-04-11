#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int n, a, b;

int f(int i) {
    return i ? i : n;
}

int main() {
    scanf("%d%d%d", &n, &a, &b);
    printf("%d\n", f((a+b+n*1000)%n));
}