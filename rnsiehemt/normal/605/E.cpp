#include <bits/stdc++.h>
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef double real;

const int MaxN = 1005;

int N;
real p[MaxN][MaxN], e[MaxN], cure[MaxN], curp[MaxN];
bool seen[MaxN];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        int k; scanf("%d", &k);
        p[i][j] = k/100.;
    }

    e[N-1] = 0;
    std::fill(e, e+N-1, 1e9);
    for (int i = 0; i < N; i++) {
        int best = 0;
        for (int j = 0; j < N; j++) if (!seen[j]) best = j;
        for (int j = 0; j < N; j++) if (!seen[j] && e[j] < e[best]) best = j;
        seen[best] = true;
        for (int j = 0; j < N; j++) if (!seen[j]) {
            real pgo = (1-curp[j]) * p[j][best];
            real ncure = cure[j] + pgo * e[best];
            real ncurp = curp[j] + pgo;
            real ne = ncure / ncurp + 1 / ncurp;
            if (domin(e[j], ne)) {
                cure[j] = ncure;
                curp[j] = ncurp;
            }
        }
    }
    printf("%.8lf\n", e[0]);
}