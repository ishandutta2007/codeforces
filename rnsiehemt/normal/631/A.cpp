#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 1005;

int N, a[MaxN], b[MaxN], ans;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", a+i);
    for (int i = 0; i < N; i++) scanf("%d", b+i);
    for (int i = 0; i < N; i++) {
        int x = 0, y = 0;
        for (int j = i; j < N; j++) {
            x |= a[j]; y |= b[j];
            domax(ans, x+y);
        }
    }
    printf("%d\n", ans);
}