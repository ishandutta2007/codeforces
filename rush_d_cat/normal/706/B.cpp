#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <map>
#include <cmath>
using namespace std;
typedef __int64 ll;
int x[100000 + 10];
int sum[100000 + 10];
int main()
{
    int n, i, tmp ,q, m;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> tmp;
        x[tmp] ++;
    }
    for(i = 1; i <= 100000; i++)
    {
        sum[i] = sum[i - 1] + x[i];
    }
    cin >> q;
    for(i = 1; i <= q; i++)
    {
        cin >> m;
        if(m >= 100000)
        {
            cout << sum[100000] << endl;
        } else {
            cout << sum[m] << endl;
        }
    }
    return 0;
}