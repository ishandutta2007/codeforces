#include <iostream>

using namespace std;

int N, M;
int g[55][55];

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            char c;
            cin >> c;
            if (c == '#')
                g[i][j] = 1;
            else
                g[i][j] = 0;
        }

    bool bad = false;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < N; k++)
                for (int l = 0; l < M; l++)
                {
                    if (g[i][j] && g[k][j] && g[i][l] && !g[k][l])
                        bad = true;
                }
    if (bad)
        cout << "No\n";
    else
        cout << "Yes\n";
}