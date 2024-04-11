#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 1000005;

int N, w[MaxN], c[MaxN+100], ans;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &w[i]);
    
    std::sort(w, w+N);
    for (int i = 0; i < N; i++) c[w[i]]++;
    for (int i = 0; i+1 < MaxN+100; i++) {
        c[i+1] += c[i]/2;
        c[i] %= 2;
        if (c[i]) ans++;
    }
    printf("%d\n", ans);
}