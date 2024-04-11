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
    int m,n,sum,max,a[100],b[100];
    cin>>n;
    for (int i=0;i<n;i++)
      cin>>a[i];
    cin>>m;
    for (int i=0;i<m;i++)
      cin>>b[i];
    max=0;
    for (int i=0;i<m;i++)
      for (int j=0;j<n;j++)
        if (b[i]%a[j]==0)
        {
            if ((b[i]/a[j])>max) max=b[i]/a[j];
        }
    sum=0;
    for (int i=0;i<m;i++)
      for (int j=0;j<n;j++)
        if ((b[i]%a[j]==0)&&(b[i]/a[j]==max)) sum++;
    cout<<sum<<endl;
    return 0;
}