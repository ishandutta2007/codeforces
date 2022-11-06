#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define i64 long long
using namespace std;

bool P[166][166];

int N, K, T, i, j, H, h, _h, Nv[3], Crucial[40];

int Bithei(int x)
{
    int H = 0;
    while (x != 1)
        {
            x >>= 1;
            H++;
        }
    return H;
}

void Newnode(int cnt)
{
    int i, k;
    fortodo(k, 1, cnt)
        {
            N++;
            fortodo(i, 1, Nv[0])
                P[Nv[i]][N] = P[N][Nv[i]] = true;
        }
    Nv[0] = cnt;
    N -= cnt;
    fortodo(k, 1, cnt)
        {
            N++;
            Nv[k] = N;
        }
}

int main()
{
    scanf("%d", &K);
    if (K == 1)
        {
            printf("2\nNY\nYN\n");
            return 0;
        }
    H = Bithei(K);
    fortodo(i, 1, 150)
        fortodo(j, 1, 150)
            P[i][j] = false;
    N = 2;
    T = K;
    Nv[0] = Nv[1] = 1;
    fortodo(i, 1, H)
        {
            Newnode(1);
            Crucial[i] = N;
        }
    Crucial[H + 1] = 2;
    P[2][N] = P[N][2] = true;
    if (T % 2 == 0)
        P[1][3] = P[3][1] = false;
    else
        T--;
    Nv[0] = Nv[1] = 1;
    _h = 0;
    while (T)
        {
            h = Bithei(T & (-T));
            fortodo(i, 1, h - _h) Newnode(2);
            fortodo(i, 1, Nv[0])
                P[Crucial[h + 1]][Nv[i]] = P[Nv[i]][Crucial[h + 1]] = true;
            T -= T & (-T);
            _h = h;
        }
    printf("%d\n", N);
    fortodo(i, 1, N)
        {
            fortodo(j, 1, N)
                if (P[i][j])
                    printf("Y");
                else
                    printf("N");
            printf("\n");
        }
};