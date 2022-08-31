#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    char res[110][110];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> res[i][j];
    
    bool use[110];
    for (int i = 0; i < N; i++)
        use[i] = false;
    
    for (int i = 0; i < M; i++)
    {
        char best = '0';
        for (int j = 0; j < N; j++)
            best = max (best, res[j][i]);
        
        for (int j = 0; j < N; j++)
            if (res[j][i] == best)
                use[j] = true;
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
        if (use[i]) ans++;
    cout << ans << "\n";
    return 0;
}