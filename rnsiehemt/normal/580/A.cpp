#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
#define push_back pb
#define emplace_back eb
#define mod(x) ((x)%Mod)
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 100005;

int N, a[MaxN], l[MaxN], ans;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    l[0] = ans = 1;
    for (int i = 1; i < N; i++) {
        if (a[i] >= a[i-1]) l[i] = l[i-1] + 1;
        else l[i] = 1;
        domax(ans, l[i]);
    }
    printf("%d\n", ans);
}