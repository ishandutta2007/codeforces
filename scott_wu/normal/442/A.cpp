#include <iostream>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <string>

using namespace std;

int N;
bool has[5][5];
string str = "RGBYW";

int score[5][5];

int find (int x)
{
    if (x == 0) return 0;
    if (x % 2 == 0) return find (x / 2);
    return 1 + find (x / 2);
}

int main()
{
    for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
    has[i][j] = false;
    
    cin >> N;
    string s;
    
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        int cloc = 0;
        while (str[cloc] != s[0])
            cloc++;
        
        int bloc = (s[1] - '0') - 1;
        
        has[cloc][bloc] =  true;
    }
    
    int mval = 10;
    for (int i = 0; i < (1 << 10); i++)
    {
        bool bad = false;
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                for (int l = 0; l < 5; l++)
                    for (int m = 0; m < 5; m++)
                    {
                        if (j == l && k == m)
                            continue;
                        if (!has[j][k] || !has[l][m])
                            continue;
                        
                        int s = 0, t = 0;
                        if (i & (1 << j))
                            s += (1 << j);
                        if (i & (1 << (k + 5)))
                            s += (1 << (k + 5));
                        if (i & (1 << l))
                            t += (1 << l);
                        if (i & (1 << (m + 5)))
                            t += (1 << (m + 5));
                         if (s == t)
                            bad = true;
                        }
            if (!bad)
                mval = min (mval, find (i));
            }
            cout << mval << "\n";
            //system ("Pause");
            return 0;
        }