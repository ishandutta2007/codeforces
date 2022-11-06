#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define d64 long double
#define eps 1e-11
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

struct Wall
{
    d64 X, Y;
};

struct Cannon
{
    d64 Alpha;
    double AnsX, AnsY;
    int Iden;
};

const d64 PI = 3.1415926535897932384;
const d64 Gravity = 9.8;

bool Cmp_X(Wall A, Wall B) {return (A.X < B.X);};
bool Cmp_Alp(Cannon A, Cannon B) {return (A.Alpha < B.Alpha);};
bool Cmp_Iden(Cannon A, Cannon B) {return (A.Iden < B.Iden);};

int N, M, i, j, k;
d64 V;
Wall P[100001];
Cannon C[10001];

d64 YATX(d64 X, d64 V, d64 Alpha)
{
    d64 T;
    T = X / (V * cos(Alpha));
    return V * sin(Alpha) * T - 0.5 * Gravity * T * T;
};

bool Through(Wall Q, d64 V, d64 Alpha)
{
    d64 T, Y0;
    T = Q.X / (V * cos(Alpha));
    Y0 = V * sin(Alpha) * T - 0.5 * Gravity * T * T;
    return (Y0 > Q.Y + eps);
};

d64 Anoside(d64 V, d64 Alpha)
{
    return (2.0 * V * sin(Alpha) / Gravity) * V * cos(Alpha);
};

int main()
{
    cin >> N >> V;
    fortodo(i, 1, N) cin >> C[i].Alpha;
    fortodo(i, 1, N) C[i].Iden = i;
    cin >> M;
    fortodo(i, 1, M) cin >> P[i].X >> P[i].Y;
    sort(P + 1, P + M + 1, Cmp_X);
    sort(C + 1, C + N + 1, Cmp_Alp);
    int te = 0;
    fortodo(i, 1, N)
        {
            while ((te < M) && (Through(P[te + 1], V, C[i].Alpha))) te++;
            if ((te == M) || (YATX(P[te + 1].X, V, C[i].Alpha) < eps))
                {
                    C[i].AnsX = double(Anoside(V, C[i].Alpha));
                    C[i].AnsY = 0.0;
                }
            else
                {
                    C[i].AnsX = double(P[te + 1].X);
                    C[i].AnsY = double(YATX(P[te + 1].X, V, C[i].Alpha));
                };
        };
    sort(C + 1, C + N + 1, Cmp_Iden);
    fortodo(i, 1, N)
        printf("%.9f %.9f\n", C[i].AnsX, C[i].AnsY);
};