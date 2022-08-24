#include <iostream>

using namespace std;
const int MAXN = 1100;

int N, M;
int arr[MAXN][MAXN];

bool good (int x, int y)
{
    bool l1 = true, l2 = true;
    for (int i = 0; i < N; i++)
        if (arr[i][y])
            l1 = false;
    for (int i = 0; i < M; i++)
        if (arr[x][i])
            l2 = false;
    
    return l1 || l2;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            char ch;
            cin >> ch;
            
            if (ch == 'S')
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
        }
    
    int res = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (good (i, j))
                res++;
    
    cout << res << "\n";
    return 0;
}