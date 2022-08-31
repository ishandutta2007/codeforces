#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int N;
int arr[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    int cv = 0;
    for (int i = 0; i < N / 2; i++)
        for (int j = 0; j < N / 2; j++)
        {
            int x = 2 * i, y = 2 * j;
            arr[x][y] = cv;
            if ((i + j) % 2 == 0)
            {
                arr[x+1][y] = cv + 1;
                arr[x][y+1] = cv + 2;
            }
            else
            {
                arr[x+1][y] = cv + 2;
                arr[x][y+1] = cv + 1;               
            }
            arr[x+1][y+1] = cv + 3;
            cv += 4;
        }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j) cout << " ";
            cout << arr[i][j];
        }
        cout << "\n";
    }
}