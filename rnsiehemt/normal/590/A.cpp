#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 500005;

int N, a[MaxN], ans;

void go(int i, int l) {
    if (l%2 == 1) {
        for (int j = i; j < i+l/2; j++) a[j] = a[i-1];
        for (int j = i+l/2; j < i+l; j++) a[j] = a[i+l-1];
    } else {
        for (int j = i; j < i+l; j++) a[j] = a[i-1];
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    int cur = 0;
    for (int i = 1; i < N; i++) {
        if (a[i] != a[i-1]) cur++;
        else {
            if (cur) {
                domax(ans, cur/2);
                go(i-cur, cur);
            }
            cur = 0;
        }
    }
    if (cur) {
        domax(ans, cur/2);
        go(N-cur, cur);
    }
    printf("%d\n", ans);
    for (int i = 0; i < N; i++) printf("%d%c", a[i], " \n"[i == N-1]);
}