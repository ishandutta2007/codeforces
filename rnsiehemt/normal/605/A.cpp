#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 100005;

int N, max[MaxN], ans;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);
        max[a] = max[a-1] + 1;
        domax(ans, max[a]);
    }
    printf("%d\n", N - ans);
}