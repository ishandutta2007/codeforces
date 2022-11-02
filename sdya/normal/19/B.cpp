#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

int n;
long long t[3000], c[3000];
long long d1[5000], d2[5000];

#define min(a, b) (a < b ? a : b)

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> t[i] >> c[i], t[i] ++;

    d1[0] = 0;
    for (int i = 1; i <= 4500; i ++)
        d1[i] = 1000000000000000000LL;
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 0; j <= 4500; j ++)
            d2[j] = d1[j];

        for (int j = 0; j <= 4500; j ++)
            if (j >= t[i])
                d2[j] = min(d1[j], d1[j - t[i]] + c[i]);

        for (int j = 0; j <= 4500; j ++)
            d1[j] = d2[j];
    }

    long long res = 1000000000000000000LL;
    for (int i = n; i <= 4500; i ++)
        res = min(res, d1[i]);

    cout << res << endl;


    return 0;
}