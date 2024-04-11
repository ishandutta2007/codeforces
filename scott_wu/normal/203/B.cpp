#include <iostream>

using namespace std;

bool seen[1100][1100];
int N, M;

bool good (int cx, int cy)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (!seen[cx+i][cy+j])
                return false;
    return true;
}

int main()
{
    for (int i = 0; i < 1100; i++)
        for (int j = 0; j < 1100; j++)
            seen[i][j] = false;
    cin >> N >> M;
    for (int t = 0; t < M; t++)
    {
        int x, y;
        cin >> x >> y;
        seen[x+1][y+1] = true;
        bool check = false;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (good (x-1 + i, y-1 + j))
                    check = true;
        if (check)
        {
            cout << t + 1 << "\n";
            //system ("Pause");
            return 0;
        }
    }
    cout << "-1\n";
    //system ("Pause");
    return 0;
}