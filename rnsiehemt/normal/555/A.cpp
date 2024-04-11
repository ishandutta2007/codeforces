#include <bits/stdc++.h>
typedef long long ll;
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
#define mod(x) ((x)%Mod)

int N, K, a[100005], ans;

int main()
{
    scanf("%d%d", &N, &K);
    for (int i = 0; i < K; i++) {
        int M; scanf("%d", &M);
        for (int j = 0; j < M; j++) scanf("%d", &a[j]);
        if (a[0] == 1) {
            int k = 0;
            while (k < M && a[k] == k+1) k++;
            M -= k;
            ans += M + M;
        } else {
            ans += M-1 + M;
        }
    }
    printf("%d\n", ans);
}