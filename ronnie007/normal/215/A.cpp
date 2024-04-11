#include<iostream>
#include<stdio.h>
using namespace std;


int main()
    {
    int n,m;
    int i,j;
    int a[107];
    int b[107];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        }
    scanf("%d",&m);
    for(i=0;i<m;i++)
        {
        scanf("%d",&b[i]);
        }
    int br=0;
    int mx=0;
    for(i=0;i<n;i++)
        {
        for(j=0;j<m;j++)
            {
            if(b[j]%a[i]==0)
                {
                if(b[j]/a[i]>mx)mx=b[j]/a[i];
                }
            }
        }

    for(i=0;i<n;i++)
        {
        for(j=0;j<m;j++)
            {
            if(b[j]%a[i]==0)
                {
                if(b[j]/a[i]==mx)br++;
                }
            }
        }
    printf("%d\n",br);
    return 0;
    }