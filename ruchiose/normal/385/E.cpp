#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define i64 long long
using namespace std;

i64 N, SX, SY, DX, DY;
i64 T;

struct Matrix
{
    i64 V[6][6];
    Matrix()
    {
        int i, j;
        fortodo(i, 0, 5)
            fortodo(j, 0, 5)
                V[i][j] = (i == j) ? 1 : 0;
    };
    void Evo1()
    {
        V[4][1] = 1; V[4][2] = 1; V[4][3] = 1;
        V[5][1] = 1; V[5][2] = 1; V[5][3] = 1;
    };
    void Evo2()
    {
        V[1][0] = 1;
        V[2][4] = 1; V[3][5] = 1;
    };
    Matrix operator *(Matrix Snd)
    {
        Matrix Ret;
        int i, j, k;
        fortodo(i, 0, 5)
            fortodo(j, 0, 5)
                {
                    Ret.V[i][j] = 0;
                    fortodo(k, 0, 5)
                        {
                            Ret.V[i][j] += Snd.V[i][k] * V[k][j];
                            Ret.V[i][j] %= N;
                        };
                };
        return Ret;
    };
};

Matrix E1, E2, E, A;
i64 i, j;

int main()
{
    cin >> N >> SX >> SY >> DX >> DY >> T;
    if (DX < 0) DX += N;
    if (DY < 0) DY += N;
    E1 = Matrix(); E1.Evo1();
    E2 = Matrix(); E2.Evo2();
    E = E1 * E2;
    A = Matrix();
    for (; T; T >>= 1)
        {
            if (T & 1ll) A = A * E;
            E = E * E;
        };
    i64 BAS[6], ANS[6];
    BAS[0] = 1;  BAS[1] = 0;
    BAS[2] = SX; BAS[3] = SY;
    BAS[4] = DX; BAS[5] = DY;
    fortodo(i, 0, 5)
        {
            ANS[i] = 0;
            fortodo(j, 0, 5)
                {
                    ANS[i] += BAS[j] * A.V[i][j];
                    ANS[i] %= N;
                };
        };
    ANS[2] %= N; ANS[2] += N; ANS[2] %= N;
    ANS[3] %= N; ANS[3] += N; ANS[3] %= N;
    if (ANS[2] == 0) ANS[2] = N;
    if (ANS[3] == 0) ANS[3] = N;
    cout << ANS[2] << " " << ANS[3] << endl;
};