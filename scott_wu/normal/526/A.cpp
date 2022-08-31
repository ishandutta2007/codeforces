#include <iostream>
#include <iomanip>
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
char ch[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> ch[i];
    
    bool good = false;
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if (i + 4 * j < N)
            {
                bool found = true;
                for (int k = 0; k < 5; k++)
                    if (ch[i+k*j] == '.')
                        found = false;
                good |= found;
            }
        }
    }
            
    if (good)
        cout << "yes\n";
    else
        cout << "no\n";
}