#include <iostream>
#include <string>

using namespace std;
const int MAXN = 1100;

bool adj[MAXN][MAXN];
string csol = "011100001010000111010011100001110000";

int main()
{
    int N; cin >> N;
    
    if (N == 4)
    {
        cout << "-1\n";
        return 0;
    }
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            adj[i][j] = false;
    if (N % 2 == 0)
    {
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                adj[i][j] = (int) csol[6*i+j] - '0';
    }
    
    for (int i = N - 2; i >= ((N % 2) ? 1 : 6); i-=2)
    {
        adj[i][i+1] = true;
        for (int j = 0; j < i; j++)
            adj[i+1][j] = adj[j][i] = true;
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << ((adj[i][j]) ? 1 : 0) << ' ';
        cout << "\n";
    }
    return 0;
}