#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
#define mod(x) ((x)%Mod)
#define pb push_back
#define eb emplace_back
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }

const int MaxN = 100005;

int N, a[MaxN];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        while (a[i] % 2 == 0) a[i] /= 2;
        while (a[i] % 3 == 0) a[i] /= 3;
    }
    for (int i = 0; i < N; i++) if (a[i] != a[0]) {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
}