#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <ctime>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int N, M;
int board[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            char c; cin >> c;
            if (c == '#') board[i][j] = 1;
            else board[i][j] = 0;
        }

    for (int i = 1; i < N - 1; i++)
        for (int j = 1; j < M - 1; j++)
        {
            int ct = 0;
            for (int x = -1; x <= 1; x++)
                for (int y = -1; y <= 1; y++)
                    if ((x != 0 || y != 0) && board[i+x][j+y])
                        ct++;
            if (ct == 8)
            {
                for (int x = -1; x <= 1; x++)
                    for (int y = -1; y <= 1; y++)
                        if ((x != 0 || y != 0) && board[i+x][j+y])
                            board[i+x][j+y] = 2;                
            }
        }

    bool bad = false;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (board[i][j] == 1)
                bad = true;
    if (bad) cout << "NO\n";
    else cout << "YES\n";
}