#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int a[100000 + 10], n;
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1, a+1+n);
    int ok = 0;
    for(int i=3;i<=n;i++)
    {
        if(a[i] < a[i-1] + a[i-2]) ok = 1;
    } 
    cout << (ok?"YES":"NO") << endl;
}