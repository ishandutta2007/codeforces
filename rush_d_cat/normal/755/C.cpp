#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;
int n;
int x, a[10000 + 2];
int main()
{
    cin >> n;int res = 0;
    for(int i=1;i<=n;i++)
    {
        cin >> x;
        if(x == i) res ++; 
        else a[x] = 1;
    }
    int k = 0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]) k ++; 
    }
    cout << (res + k/2) << endl;

}