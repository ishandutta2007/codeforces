#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 1000*1000+5;

int N, M, a[MaxN], c[MaxN], d[MaxN], ans, ansi;

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        if (a[i] <= M) c[a[i]]++;
    }
    for (int i = 1; i <= M; i++) for (int j = i; j <= M; j += i) d[j] += c[i];
    for (int i = 1; i <= M; i++) if (domax(ans, d[i])) ansi = i;
    if (ans) {
        printf("%d %d\n", ansi, ans);
        for (int i = 0; i < N; i++) if (ansi % a[i] == 0) printf("%d ", i+1);
        printf("\n");
    } else {
        printf("1 0\n");
    }
}