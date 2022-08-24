#include <iostream>
#include <iomanip>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

string a, b;
int val[MAXN][2];

// 0 if less, 1 if =, 2 if more
int cmp()
{
    for (int i = MAXN - 1; i >= 1; i--)
    {
        int m = min (val[i][0], val[i][1]);
        val[i][0] -= m;
        val[i][1] -= m;
        
        if (val[i][0] > 0)
        {
            if (i > 1 && val[i][0] == 1 && val[i-1][1] == 1)
            {
                val[i][0] = 0;
                val[i-1][1] = 0;
                val[i-2][0]++;
            }
            else
                return 2;
        }
        if (val[i][1] > 0)
        {
            if (i > 1 && val[i][1] == 1 && val[i-1][0] == 1)
            {
                val[i][1] = 0;
                val[i-1][0] = 0;
                val[i-2][1]++;
            }
            else
                return 0;
        }
    }
    
    if (val[0][0] < val[0][1])
        return 0;
    if (val[0][0] > val[0][1])
        return 2;
    return 1;
}
        

int main()
{
    for (int i = 0; i < MAXN; i++)
        val[i][0] = val[i][1] = 0;
    
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++)
        val[i+1][0] = (int) a[a.length() - 1 - i] - '0';
    for (int i = 0; i < b.length(); i++)
        val[i+1][1] = (int) b[b.length() - 1 - i] - '0';
    
    int x = cmp();
    if (x == 0)
        cout << "<\n";
    else if (x == 1)
        cout << "=\n";
    else
        cout << ">\n";
    
    //system ("Pause");
    return 0;
}