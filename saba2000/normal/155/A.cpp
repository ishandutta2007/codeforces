#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,a[1010],cnt=0,maxi,mini;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }
    maxi = a[0];
    mini = a[0];
     for(i=0;i<n;i++)
    {
       if(a[i]>maxi)
        {
            maxi = a[i];
            cnt++;
        }
        else if(a[i]<mini)
        {
            mini = a[i];
            cnt++;
        }
    }      printf("%d\n",cnt);
    return 0;
}