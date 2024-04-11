#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int N, K;
ll a, p;

void go() {
    if (p > 0) a += p;
    p--;
}

int main() {
    scanf("%d%d", &N, &K);
    p = N-1;
    for (int i = 0; i < K; i++) {
        go();
        go();
    }
    printf("%lld\n", a);
}