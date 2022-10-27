#include <iostream>
#include <cstring>
#include <string.h>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef __int64 ll;
int b[100000 + 10];
int abs(int x)
{
    return x < 0 ? (-x) : x;
}
int main()
{
    int n, a, i, d1 = 0, d2 = 0;
    cin >> n >> a;
    for(i = 1; i <= n; i++) cin >> b[i];
    if(n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    sort(b + 1, b + 1 + n);
    int x, y;
    x = b[1]; y = b[n - 1];
    d1 += b[n - 1] - b[1];
    d1 += min(abs(a - b[1]), abs(a - b[n - 1]));

    x = b[2]; y = b[n];
    d2 += b[n] - b[2];
    d2 += min(abs(a - b[2]), abs(a - b[n]));
    cout << min(d1, d2) << endl;
}