#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

long long n;
long long res = 0;

long long a[10];

int main()
{
    cin >> n;
    for (long long i = 1LL; i <= n; i ++)
        a[i % 9LL] ++;

    for (long long i = 0LL; i < 9LL; i ++)
        for (long long j = 0LL; j < 9LL; j ++)
            for (long long k = 0LL; k < 9LL; k ++)
                if ((i * j) % 9LL == k)
                    res += a[i] * a[j] * a[k];

    for (long long i = 1; i <= n; i ++)
        res -= n / i;
    cout << res << endl;
   
    return 0;
}