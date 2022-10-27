#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int NICO = 100000 + 10;
int n, n1, n2;
double a[NICO], b[NICO];
double val[NICO];
int used[NICO];
int main()
{
    cin >> n >> n1 >> n2;
    if(n1>n2) swap(n1,n2);
    for (int i = 1; i <= n; ++i)
    {
        cin >> val[i];
        a[i] = val[i] / n1;
        b[i] = val[i] / n2;
    }
    sort(a+1, a+1+n);
    sort(b+1, b+1+n);
    double res = 0;
    for(int i=n;i>=n-n1+1;i--)
    {
        res += a[i];
    }
    for(int i=n-n1;i>=n-n1-n2+1;i--)
    {
        res += b[i];
    }
    printf("%.8f\n", res);
}