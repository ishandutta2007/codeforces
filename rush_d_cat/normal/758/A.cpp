#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
const int NICO = 1000 + 10;
int a[NICO], n;
int main()
{
    cin >> n;int p=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        p=max(p,a[i]);
    }
    int res = 0;
    for(int i=1;i<=n;i++)
    {
        res+=p-a[i];
    }
    cout<<res<<endl;
}