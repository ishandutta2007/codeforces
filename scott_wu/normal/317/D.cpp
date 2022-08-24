#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXD = 100100;

bool use[MAXD];

int sg[31] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, 14};

int main()
{
    for (int i = 0; i < MAXD; i++)
        use[i] = false;
        
    ll n; cin >> n;
    
    int ncount = 0;
    int res = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (use[i]) continue;
        
        ll cval = i;
        int count = 0;
        while (cval <= n)
        {
            if (cval < 100100)
                use[cval] = true;
            
            ncount++;
            count++;
            cval *= i;
        }
        
        res ^= sg[count];
    }
    
    if ((n - ncount) & 1)
        res ^= 1;
    
    if (res)
        cout << "Vasya\n";
    else
        cout << "Petya\n";
    //system ("Pause");
    return 0;
}