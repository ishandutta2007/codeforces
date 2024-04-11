#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;

string str;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> str;
    
    int res = 0;
    int N = str.length();
    for (int i = 0; i < N; i++)
        res = max (res, (int) (str[i] - '0'));
    
    cout << res << "\n";
    for (int i = 0; i < res; i++)
    {
        if (i > 0) cout << " ";
        
        bool flag = false;
        for (int j = 0; j < N; j++)
        {
            if ((int) str[j] - '0' > i)
                flag = true;
            if (flag)
            {
                if ((int) str[j] - '0' > i)
                    cout << 1;
                else
                    cout << 0;
            }
        }
        
    }
    cout << "\n";
    return 0;
}