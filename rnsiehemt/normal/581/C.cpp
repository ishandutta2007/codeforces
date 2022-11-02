#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
#define push_back pb
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
typedef long long ll;

int N, K, c[105], r;

int main()
{
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        int a; scanf("%d", &a);
        c[a]++;
        r += a/10;
    }

    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j <= 9; j++) {
            int k = 10*j + i;
            while (c[k] && K >= 10 - i) {
                K -= 10 - i;
                c[k]--;
                c[10*(j+1)]++;
                r++;
            }
        }
    }

    printf("%d\n", r);
}