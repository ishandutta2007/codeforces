#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
#define mod(x) ((x)%Mod)
#define pb push_back
#define eb emplace_back
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }

const int MaxN = 100005;

int N, h[MaxN], t[MaxN], ans;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &h[i]);
    int cur = 1;
    for (int i = 0; i < N; i++) {
        domin(cur, h[i]);
        t[i] = cur;
        cur++;
    }
    cur = 1;
    for (int i = N-1; i >= 0; i--) {
        domin(cur, h[i]);
        domin(t[i], cur);
        cur++;
    }
    for (int i = 0; i < N; i++) domax(ans, t[i]);
    printf("%d\n", ans);
}