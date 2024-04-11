#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 200005;

int N, M, a[MaxN], b;

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    std::sort(a, a+N);
    for (int i = 0; i < M; i++) {
        scanf("%d", &b);
        printf("%d%c", int(std::upper_bound(a, a+N, b) - a), " \n"[i == M-1]);
    }
}