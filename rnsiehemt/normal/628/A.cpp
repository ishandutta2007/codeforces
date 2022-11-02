#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int N, B, P, b, p;

int main()
{
    scanf("%d%d%d", &N, &B, &P);
    p = N*P;
    while (N > 1) {
        int k = 1;
        while (k*2 <= N) k *= 2;
        b += B*k + k/2;
        N = N-k/2;
    }
    printf("%d %d\n", b, p);
}