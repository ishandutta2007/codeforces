#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int MAXN = 200000 + 10;
int a[MAXN];
int main()
{
    int n, i; cin >> n;
    int ok = 1;
    for(i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(i = 1; i < n; i++)
    {
        if((a[i]%2) != 0)
        {
            a[i]-=1;
            a[i+1]-=1;
        }
    }
    for(i = 1; i <= n; i++)
    {
        if(a[i] < 0) ok = 0;
    }
    if(a[n] % 2 != 0) ok = 0;
    if(ok) cout << "YES";
    else cout << "NO";
}