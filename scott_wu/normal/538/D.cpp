#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 110;

int N;
char board[MAXN][MAXN];
bool bad[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            bad[i][j] = false;
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j] == 'o')
            {
                for (int k = 0; k < N; k++)
                    for (int l = 0; l < N; l++)
                    {
                        if (board[k][l] == '.')
                            bad[(k-i+N)][(l-j+N)] = true;
                    }
            }
    
    /*for (int i = 1; i < 2 * N; i++)
    {
        for (int j = 1; j < 2 * N; j++)
            cout << ((bad[i][j]) ? 1 : 0);
        cout << "\n";
    }*/
    
    bool works = true;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j] == 'x')
            {
                bool found = false;
                for (int k = 0; k < N; k++)
                    for (int l = 0; l < N; l++)
                    {
                        if (board[k][l] == 'o' && !bad[i-k+N][j-l+N])
                            found = true;
                    }
                if (!found)
                    works = false;
            }
    
    if (!works)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        for (int i = 1; i < 2 * N; i++)
        {
            for (int j = 1; j < 2 * N; j++)
            {
                if (i == N && j == N) cout << 'o';
                else cout << ((bad[i][j]) ? '.' : 'x');
            }
            cout << "\n";
        }
    }
    return 0;
}