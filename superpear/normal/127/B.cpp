#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>

#define maxlongint 2147483647;

using namespace std;

int main()
{
    int n,e,sum,a[1000];
    cin>>n;
    for (int i=1;i<=n;i++)
      cin>>a[i];
    sort(a+1,a+n+1);
    e=1;
    sum=0;
    for (int i=2;i<=n;i++)
    {
        if (a[i]!=a[i-1])
        {
            sum+=e/2;
            e=1;
        }
        else
            e++;
    }
    sum+=e/2;
    cout<<sum/2<<endl;
    return 0;
}