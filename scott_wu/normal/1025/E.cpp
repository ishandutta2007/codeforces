#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
const int MAXM = 55;

int N, M;
int cx[MAXM], cy[MAXM];
int pperm[MAXM];
int startx[MAXM], starty[MAXM];
int goalx[MAXM], goaly[MAXM];
vector <int> res, vres;
vector <int> cres;
int board[MAXM][MAXM];

void add_move (int x1, int y1, int x2, int y2)
{
    cres.push_back(x1 * MAXM + y1);
    cres.push_back(x2 * MAXM + y2);
    swap (board[x1][y1], board[x2][y2]);
}

void lessgo()
{
    for (int i = 0; i < MAXM; i++)
        for (int j = 0; j < MAXM; j++)
            board[i][j] = -1;
    for (int i = 0; i < M; i++)
        board[cx[i]][cy[i]] = i;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            if (board[i][j] != -1)
            {
                int xcur = i, ycur = j;
                while (xcur > 1)
                {
                    if (board[xcur-1][ycur] == -1)
                    {
                        add_move (xcur, ycur, xcur - 1, ycur);
                        xcur--;
                        continue;
                    }
                    bool found = false;
                    for (int k = ycur; k >= 1; k--)
                    {
                        if (board[xcur-1][k] == -1)
                        {
                            for (int m = k + 1; m <= ycur; m++)
                            {
                                add_move (xcur - 1, m, xcur - 1, m - 1);
                            }
                            add_move (xcur, ycur, xcur - 1, ycur);
                            xcur--;
                            found = true;
                            break;
                        }
                    }
                    if (found) continue;

                    for (int k = ycur; k <= N; k++)
                    {
                        if (board[xcur-1][k] == -1)
                        {
                            for (int m = k - 1; m >= ycur; m--)
                            {
                                add_move (xcur - 1, m, xcur - 1, m + 1);
                            }
                            add_move (xcur, ycur, xcur - 1, ycur);
                            xcur--;
                            found = true;
                            break;
                        }
                    }
                }
            }
        }

    for (int i = 1; i <= N; i++)
    {
        if (board[1][i] != -1)
        {
            for (int j = i - 1; j >= 1; j--)
            {
                if (board[1][j] == -1 && board[1][j+1] != -1)
                {
                    add_move (1, j + 1, 1, j);
                }
            }
        }
    }
}

void gperm()
{
    // assume pperm is filled and cx = 0
    for (int i = 1; i <= N; i++)
    {
        if (pperm[i] != -1)
        {
            for (int j = i; j <= N; j++)
            {
                if (board[1][j] == pperm[i])
                {
                    if (j == i) break;
                    add_move (1, j, 2, j);
                    for (int k = j - 1; k >= i; k--)
                        if (board[1][k] != -1)
                            add_move (1, k, 1, k + 1);
                    for (int k = j; k >= i + 1; k--)
                        add_move (2, k, 2, k - 1);
                    add_move (2, i, 1, i);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    int cs = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> startx[i] >> starty[i];
        cs += startx[i];
    }
    for (int i = 0; i < M; i++)
    {
        cin >> goalx[i] >> goaly[i];
        cs += goalx[i];
    }

    if (N == 1)
    {
        cout << "0\n";
        return 0;
    }

    bool yolo = false;
    if (cs > N * M)
    {
        yolo = true;
        for (int i = 0; i < M; i++)
        {
            startx[i] = N + 1 - startx[i];
            starty[i] = N + 1 - starty[i];
            goalx[i] = N + 1 - goalx[i];
            goaly[i] = N + 1 - goaly[i];
        }
    }

    for (int i = 0; i < M; i++)
    {
        cx[i] = goalx[i];
        cy[i] = goaly[i];
    }
    cres.clear();
    lessgo();
    for (int i = 0; i < cres.size(); i++)
        vres.push_back(cres[(int) cres.size() - 1 - i]);
    for (int i = 1; i <= N; i++)
        pperm[i] = board[1][i];

    for (int i = 0; i < M; i++)
    {
        cx[i] = startx[i];
        cy[i] = starty[i];
    }
    cres.clear();
    lessgo();
    for (int i = 0; i < cres.size(); i++)
        res.push_back(cres[i]);

    cres.clear();
    gperm();
    
    for (int i = 0; i < cres.size(); i++)
        res.push_back(cres[i]);
    for (int i = 0; i < vres.size(); i++)
        res.push_back(vres[i]);
    cout << res.size() / 2 << "\n";
    for (int i = 0; i < res.size(); i += 2)
    {
        int a = res[i] / MAXM, b = res[i] % MAXM, c = res[i+1] / MAXM, d = res[i+1] % MAXM;
        if (yolo)
        {
            a = N + 1 - a;
            b = N + 1 - b;
            c = N + 1 - c;
            d = N + 1 - d;
        }
        cout << a << " " << b << " " << c << " " << d << "\n"; // decompose later
    }
}