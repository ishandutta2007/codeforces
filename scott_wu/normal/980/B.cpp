#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

int N, M;
int v[100][4];

int main()
{
    cin >> N >> M;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 100; j++)
            v[i][j] = 0;

    for (int i = 1; i < N / 2; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            if (M >= 2)
            {
                v[i][j] = v[N-1-i][j] = 1;
                M -= 2;
            }
        }
    }
    for (int i = 1; i <= 2; i++)
        if (M)
        {
            v[N/2][i] = 1;
            M--;
        }

    cout << "YES\n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (v[j][i]) cout << "#";
            else cout << ".";
        }
        cout << "\n";
    }
}