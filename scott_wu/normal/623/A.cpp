#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 510;

int N, M;
bool has[MAXN][MAXN];

int lres[MAXN];

void flood (int cloc, int val)
{
    if (lres[cloc] != 0)
        return;
    lres[cloc] = val;
    for (int i = 0; i < N; i++)
        if (has[cloc][i])
            flood (i, 3 - val);
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            has[i][j] = (i != j);
    
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        has[a][b] = has[b][a] = false;
    }
    
    for (int i = 0; i < N; i++)
        lres[i] = 0;
    
    for (int i = 0; i < N; i++)
    {
        bool seen = false;
        for (int j = 0; j < N; j++)
            if (has[i][j])
            {
                flood (i, 1);
                seen = true;
                break;
            }
        if (seen) break;
    }
    
    bool win = true;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (has[i][j] != (lres[i] + lres[j] == 3))
                win = false;
        }
    
    if (win)
    {
        cout << "Yes\n";
        for (int i = 0; i < N; i++)
        {
            if (lres[i] == 0) cout << 'b';
            if (lres[i] == 1) cout << 'a';
            if (lres[i] == 2) cout << 'c';
        }
        cout << "\n";
        //system ("Pause");
    }
    else
        cout << "No\n";
    return 0;
}