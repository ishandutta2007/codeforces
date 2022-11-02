#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

typedef long double real;
const int MaxN = 105, MaxM = 1005;

int N, M, x[MaxN], foo;
real p[2][MaxN*MaxM];

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &x[i]);
        foo += x[i];
    }
    
    if (M == 1) {
        printf("1.00000000000\n");
        return 0;
    }

    p[0][0] = 1;
    int cur = 1, prev = 0, Max = N*M+1;
    for (int i = 0; i < N; i++) {
        std::fill(p[cur], p[cur] + Max, 0.L);
        real s = 0;
        for (int j = 0; j < M; j++) {
            real r = s;
            if (j - x[i] >= 0) r -= p[prev][j - x[i]];
            p[cur][j] = r / (M-1);
            s += p[prev][j];
        }
        for (int j = M; j <= Max; j++) {
            real r = s - p[prev][j - x[i]];
            p[cur][j] = r / (M-1);
            s += p[prev][j] - p[prev][j-M];
        }
        std::swap(cur, prev);
    }
    
    real ansp = 0;
    for (int i = 0; i < foo; i++) ansp += p[prev][i];
    //printf("%lf\n", ansp);
    printf("%.11lf\n", double(ansp * (M-1) + 1));
}