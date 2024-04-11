#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 300100;

int N, M;
vector <int> board[MAXN];

vector <int> res[MAXN];
vector <int> res2[MAXN];
vector <int> vt[MAXN];
string lookup = "ACGT";

int bval[2][MAXN][4];
int setup[2][MAXN];

int figure()
{
    // swap N and M!!!
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < MAXN; j++)
            for (int k = 0; k < 4; k++)
                bval[i][j][k] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int t = i % 2, u = j, v = board[i][j];
            bval[t][u][v]++;
        }
    }

    int ans = 0;
    int na = -1, nb = -1;
    for (int a = 0; a < 4; a++)
        for (int b = a + 1; b < 4; b++)
        {
            int c = 0, d = 0;
            while (c == a || c == b)
                c++;
            d = 6 - a - b - c;

            int r = 0;
            for (int i = 0; i < M; i++)
            {
                if (i % 2 == 0)
                {
                    r += max (bval[0][i][a] + bval[1][i][b], bval[1][i][a] + bval[0][i][b]);
                }
                else
                {
                    r += max (bval[0][i][c] + bval[1][i][d], bval[1][i][c] + bval[0][i][d]);
                }
            }
            ans = max (ans, r);
            if (ans == r)
            {
                na = a;
                nb = b;
            }
        }

    {
        int a = na, b = nb;
        int c = 0, d = 0;
        while (c == a || c == b)
            c++;
        d = 6 - a - b - c;

        for (int i = 0; i < M; i++)
        {
            if (i % 2 == 0)
            {
                if (bval[0][i][a] + bval[1][i][b] > bval[1][i][a] + bval[0][i][b])
                {
                    setup[0][i] = a;
                    setup[1][i] = b;
                }
                else
                {
                    setup[1][i] = a;
                    setup[0][i] = b;
                }
            }
            else
            {
                if (bval[0][i][c] + bval[1][i][d] > bval[1][i][c] + bval[0][i][d])
                {
                    setup[0][i] = c;
                    setup[1][i] = d;
                }
                else
                {
                    setup[1][i] = c;
                    setup[0][i] = d;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        res[i].clear();
        for (int j = 0; j < M; j++)
            res[i].push_back(setup[i%2][j]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            int v = -1;
            for (int k = 0; k < 4; k++)
                if (s[j] == lookup[k])
                {
                    v = k;
                    break;
                }
            board[i].push_back(v);
        }
    }

    int ans = figure();
    for (int i = 0; i < N; i++)
    {
        res2[i] = res[i];
        res[i].clear();
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            vt[j].push_back(board[i][j]);
    for (int i = 0; i < N; i++)
        board[i].clear();
    for (int i = 0; i < M; i++)
    {
        board[i] = vt[i];
        vt[i].clear();
    }
    swap (N, M);
    int ans2 = figure();
    swap (N, M);
    if (ans2 > ans)
    {
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
                vt[j].push_back(res[i][j]);
        }
        for (int i = 0; i < M; i++)
            res[i].clear();
        for (int i = 0; i < N; i++)
        {
            res[i] = vt[i];
            vt[i].clear();
        }
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            res[i] = res2[i];
        }
    }

    //cout << max (ans, ans2) << "\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << (char) (lookup[res[i][j]]);
        }
        cout << "\n";
    }
}