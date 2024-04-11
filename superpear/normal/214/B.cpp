#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int n,cs,a[10],sum=0,flag;
    cin>>n;
    memset(a,0,sizeof(a));
    for (int i=0;i<n;i++)
    {
        cin>>cs;
        a[cs]++;
        sum+=cs;
    }
    if (a[0]==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    if (sum%3==1)
    {
        if (a[1]>0) a[1]--; else
        if (a[4]>0) a[4]--; else
        if (a[7]>0) a[7]--; else
        for (int i=1;i<=2;i++)
        {
            if (a[2]>0) a[2]--; else
            if (a[5]>0) a[5]--; else
            if (a[8]>0) a[8]--; else
            {
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    else
      if (sum%3==2)
      {
          if (a[2]>0) a[2]--; else
          if (a[5]>0) a[5]--; else
          if (a[8]>0) a[8]--; else
          for (int i=1;i<=2;i++)
          {
              if (a[1]>0) a[1]--; else
              if (a[4]>0) a[4]--; else
              if (a[7]>0) a[7]--; else
              {
                  cout<<-1<<endl;
                  return 0;
              }
          }
      }
    flag=1;
    for (int i=9;i>=0;i--)
      for (int j=1;j<=a[i];j++)
      {
          if ((i!=0)||(flag==0))
          {
              cout<<i;
              flag=0;
          }
      }
    if (flag==1) cout<<0;
    cout<<endl;
    return 0;
}