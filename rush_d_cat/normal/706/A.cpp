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
double x[1002], y[1002], v[1002];
int main()
{
    int a, b, n, i;
    double res = 50000;
    cin >> a >> b >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i] >> v[i];
        double tmp = sqrt((x[i] - a) * (x[i] - a) + (y[i] - b) * (y[i] - b)) / v[i];
        if(tmp < res) res = tmp;
    }
    printf("%.9f\n", res);
    return 0;
}