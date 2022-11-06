// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MOD = 1000000007;

void LEG(int &x)
{
    x %= MOD;
    if (x < 0) x += MOD;
}

void att(int &x, int y)
{
    LEG(x += y);
}

void dea(int &x, int y)
{
    LEG(x -= y);
}

const int M = 3;

int N, ox, oy;
char map[4][10010];
bool A[10010][4];

bool IEU() {return (ox >= 3) && A[ox - 1][oy] && A[ox - 2][oy];}
bool IED() {return (ox <= N - 2) && A[ox + 1][oy] && A[ox + 2][oy];}
bool IEL() {return (oy == 3) && A[ox][1] && A[ox][2];}
bool IER() {return (oy == 1) && A[ox][2] && A[ox][3];}
void FAU() {A[ox - 1][oy] ^= true; A[ox - 2][oy] ^= true;}
void FAD() {A[ox + 1][oy] ^= true; A[ox + 2][oy] ^= true;}
void FAL() {A[ox][1] ^= true; A[ox][2] ^= true;}
void FAR() {A[ox][2] ^= true; A[ox][3] ^= true;}

bool Judge(int x)
{
    if ((x & 1) && (!IEU())) return false;
    if ((x & 2) && (!IED())) return false;
    if ((x & 4) && (!IEL())) return false;
    if ((x & 8) && (!IER())) return false;
    return true;
}

void Flip(int x)
{
    if (x & 1) FAU();
    if (x & 2) FAD();
    if (x & 4) FAL();
    if (x & 8) FAR();
}

int dp[10010][8];

int calc()
{
    int i, j;
    fortodo(i, 0, N)
        fortodo(j, 0, 7)
            dp[i][j] = 0;
    dp[0][0] = 1;
    fortodo(i, 1, N)
        {
            int c = (int(A[i][3]) << 2) + (int(A[i][2]) << 1) + A[i][1];
            int w;
            fortodo(j, 0, 7)
                if ((j & c) == j)
                    fortodo(w, 0, 2)
                        if (((j & (w * 3)) == 0) && (((w * 3) & c) == (w * 3)))
                            att(dp[i][c ^ j ^ (w * 3)], dp[i - 1][j]);
        }
    return dp[N][0];
}

int main()
{
    scanf("%d", &N);
    int i, j;
    fortodo(i, 1, M)
        {
            scanf("%s", map[i] + 1);
            fortodo(j, 1, N)
                A[j][i] = (map[i][j] == '.');       
        }
    fortodo(i, 1, N)
        fortodo(j, 1, M)
            if (map[j][i] == 'O')
                {
                    ox = i;
                    oy = j;
                }
    int ans[16];
    fortodo(i, 1, 15)
        if (Judge(i))
            {
                Flip(i);
                ans[i] = calc();
                Flip(i);
            }
        else
            ans[i] = 0;
    for (i = 15; i; i--)
        fortodo(j, i + 1, 15)
            if ((j & i) == i)
                dea(ans[i], ans[j]);
    int ret = 0;
    fortodo(i, 1, 15) att(ret, ans[i]);
    printf("%d\n", ret);
}