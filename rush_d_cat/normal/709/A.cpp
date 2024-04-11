#include <iostream>
#include <cstring>
#include <string.h>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef __int64 ll;
int n, b, d, tot = 0, tmp, i, res = 0;
int main()
{
    cin >> n >> b >> d;
    for(i = 1; i <= n; i++)
    {
        cin >> tmp;
        if(tmp > b) continue;
        tot += tmp;
        if(tot > d)
        {
            res ++;tot = 0;
        }
    }
    cout << res;
}