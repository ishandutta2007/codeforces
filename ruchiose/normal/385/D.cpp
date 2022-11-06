#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define i64 long long
using namespace std;

int N, L, R, i, j, X[20], Y[20], A[20];
int Field;

double DP[1048576], ofa;

const double Trans = 180.0 / 3.1415926536; 

inline double cot(double x) {return cos(x) / sin(x);};

int main()
{
    scanf("%d%d%d", &N, &L, &R);
    fortodo(i, 0, N - 1) scanf("%d%d%d", &X[i], &Y[i], &A[i]);
    Field = (1 << N) - 1;
    fortodo(i, 0, Field)
        {
            DP[i] = L;
            fortodo(j, 0, N - 1)
                if (i & (1 << j))
                    {
                        ofa = atan2(-Y[j], DP[i - (1 << j)]-X[j]) * Trans;
                        ofa += A[j];
                        ofa /= Trans;
                        if (ofa >= 0.0)
                            {
                                DP[i] = R;
                                continue;
                            }
                        DP[i] = max(DP[i], X[j] + cot(-ofa) * Y[j]);
                    }
            DP[i] = min(DP[i], double(R));
        }
    printf("%.9f\n", DP[Field] - L);
};