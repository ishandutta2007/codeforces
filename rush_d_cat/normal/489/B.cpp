#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int NICO = 30002;
int a[NICO], b[NICO];
int n, m, res, x;
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> x;
        a[x] ++;
    }
    cin >> m;
    for(int i=1;i<=m;i++)
    {
        cin >> x;
        b[x] ++;
    }
    for(int i=1;i<=100;i++)
    {
        int tmp;
        tmp = min(a[i], b[i-1]), res+=tmp;
        a[i] -= tmp, b[i-1] -=  tmp;
        tmp = min(a[i], b[i]), res+=tmp;
        a[i] -= tmp, b[i] -= tmp;
        tmp = min(a[i], b[i+1]), res+=tmp; 
        a[i] -= tmp, b[i+1] -= tmp;
    }
    cout << res << endl;
}