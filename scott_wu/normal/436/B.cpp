#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 2100;

int N, M, K;
int res[MAXN];

int main()
{
    cin >> N >> M >> K;
    for (int i = 0; i < MAXN; i++)
        res[i] = 0;
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            char ch; cin >> ch;
            
            if (ch == 'L')
            {
                if (j - i >= 0)
                    res[j-i]++;
            }
            else if (ch == 'R')
            {
                if (j + i < M)
                    res[j+i]++;
            }
            else if (ch == 'U')
            {
                if (i % 2 == 0)
                    res[j]++;
            }
            else if (ch == 'D')
            {
                
            }
        }
    
    for (int i = 0; i < M; i++)
    {
        if (i > 0) cout << " ";
        cout << res[i];
    }
    cout << "\n";
    
    //system ("Pause");
    return 0;
}