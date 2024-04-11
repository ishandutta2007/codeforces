#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;
typedef long long ll;
const int MAXN = 55;

int N, M;
string s;
int c[MAXN];
int z[MAXN][2];
ll dp[MAXN];
ll ndp[MAXN];

void run()
{
    for (int i = 0; i <= M; i++)
    {
        ndp[z[i][0]] += dp[i];
        ndp[z[i][1]] += dp[i];
    }

    for (int i = 0; i <= M; i++)
    {
        dp[i] = ndp[i];
        ndp[i] = 0;
    }
}

int main()
{
    cin >> N >> s;
    M = s.length();
    for (int i = 0; i < M; i++)
    {
        int cc = s[i] - '0';
        c[i] = cc;
        int ind = z[i][cc];
        z[i][cc] = i + 1;
        for (int j = 0; j < 2; j++)
            z[i+1][j] = z[ind][j];
        //cout << z[i][0] << " " << z[i][1] << "\n";
    }
    z[M][0] = z[M][1] = M;

    for (int i = 0; i <= M; i++)
        dp[i] = 0;
    dp[0] = 1;
    for (int i = 0; i < N; i++)
    {
        run ();
    }

    ll res = dp[M];
    //cout << res << "\n";
    for (int i = 1; i < M; i++)
    {
        int cstart = 0;
        for (int j = M - i; j < M; j++)
            cstart = z[cstart][c[j]];
        for (int j = 0; j <= M; j++)
            dp[j] = 0;
        dp[cstart] = 1;
        for (int j = i; j < N; j++)
            run ();

        //for (int j = 0; j <= M; j++)
        //    cout << dp[j] << " ";

        for (int j = M - i; j < M; j++)
        {
            int cloc = j;
            bool bad = false;
            for (int k = M - i; k < M; k++)
            {
                if (cloc == M) bad = true;
                cloc = z[cloc][c[k]];
            }
            //cout << j << " " << dp[j] << "\n";
            //if (bad) cout << "YO\n";
            //if (cloc != M) cout << "YO\n";
            if (cloc == M && !bad)
                res += dp[j];
        }
    }
    cout << res << "\n";
}