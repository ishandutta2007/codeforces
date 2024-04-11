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

typedef int BiArr[155][155];

int N, M;

int calcRect(BiArr a, int x1, int x2, int y1, int y2)
{
    int ret = a[x2][y2] + a[x1 - 1][y1 - 1] - a[x1 - 1][y2] - a[x2][y1 - 1];
    while (ret >= MOD) ret -= MOD;
    while (ret < 0) ret += MOD;
    return ret;
}

void LEG(int &x)
{
    x %= MOD;
    x += MOD;
    x %= MOD;
}

void att(int &x, int y)
{
    LEG(x += y);
}

void deatt(int &x, int y)
{
    LEG(x -= y);
}

void makePrefix(BiArr a, BiArr s)
{
    int i, j;
    fortodo(i, 0, M)
        fortodo(j, 0, M)
            s[i][j] = 0;
    fortodo(i, 1, M)
        fortodo(j, 1, M)
            {
                LEG(s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]);
                att(s[i][j], a[i][j]);
            }
}

void clear(BiArr p)
{
    int i, j;
    fortodo(i, 0, M)
        fortodo(j, 0, M)
            p[i][j] = 0;
}

BiArr dp[155][2][2], pref[2][2];

#define y1 y2333333333333
#define y2 y_2333333333333

int main()
{
    scanf("%d%d", &N, &M);
    int x, y1, y2, t1, t2;
    fortodo(t1, 0, 1)
        fortodo(t2, 0, 1)
            clear(dp[1][t1][t2]);
    fortodo(y1, 1, M)
        fortodo(y2, y1, M)
            dp[1][0][0][y1][y2] = 1;
    fortodo(x, 2, N)
        {
            fortodo(t1, 0, 1)
                fortodo(t2, 0, 1)
                    {
                        makePrefix(dp[x - 1][t1][t2], pref[t1][t2]);
                        clear(dp[x][t1][t2]);
                    }
            fortodo(y1, 1, M)
                fortodo(y2, y1, M)
                    {
                        att(dp[x][0][0][y1][y2], calcRect(pref[0][0], y1, y2, y1, y2));
                        att(dp[x][0][1][y1][y2], calcRect(pref[0][0], y1, y2, y2 + 1, M));
                        att(dp[x][1][0][y1][y2], calcRect(pref[0][0], 1, y1 - 1, y1, y2));
                        att(dp[x][1][1][y1][y2], calcRect(pref[0][0], 1, y1 - 1, y2 + 1, M));
                        att(dp[x][0][1][y1][y2], calcRect(pref[0][1], y1, y2, y2, M));
                        att(dp[x][1][1][y1][y2], calcRect(pref[0][1], 1, y1 - 1, y2, M));
                        att(dp[x][1][0][y1][y2], calcRect(pref[1][0], 1, y1, y1, y2));
                        att(dp[x][1][1][y1][y2], calcRect(pref[1][0], 1, y1, y2 + 1, M));
                        att(dp[x][1][1][y1][y2], calcRect(pref[1][1], 1, y1, y2, M));
                    }
        }
    i64 ans = 0;
    fortodo(x, 1, N)
        {
            i64 Sum = 0;
            fortodo(y1, 1, M)
                fortodo(y2, y1, M)
                    fortodo(t1, 0, 1)
                        fortodo(t2, 0, 1)
                            Sum += dp[x][t1][t2][y1][y2];
            Sum %= MOD;
            ans += Sum * (N - x + 1);
            ans %= MOD;
        }
    cout << ans << endl;
}