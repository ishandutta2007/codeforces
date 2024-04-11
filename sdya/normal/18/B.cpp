#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

long long n, d, m, l;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> d >> m >> l;
    for (long long B = 1; B <= n; B ++)
    {
        long long L = ((B - 1LL) * m + l) / d;
        long long R = (B * m) / d;

        while (L * d <= (B - 1LL) * m + l) L ++;
        while (R * d >= B * m) R --;

        if (L <= R)
        {
            cout << (L * d) << endl;
            return 0;
        }
    }

    long long C = ((n - 1LL) * m + l) / d;
    while (C * d <= (n - 1LL) * m + l) C ++;
    cout << (C * d) << endl;
    return 0;
}