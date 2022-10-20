#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
    {
    int n,m;
    int a[1024];
    int b[1024];
    int i,j;
    int g;
    int res=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
        {
        scanf("%d",&a[i]);
        b[i]=a[i];
        }
    sort(b,b+m);
    int br=n;
    while(br>0)
        {
        g=b[m-1];
        br--;
        b[m-1]--;
        res+=g;
        for(i=m-1;i>=0;i--)
            {
            if(b[i]==g)
                {
                br--;
                res+=g;
                b[i]--;
                if(br==0)
                    {
                    break;
                    }
                }
            else break;
            }
        if(br==0)break;
        sort(b,b+m);
        }
    printf("%d ",res);
    for(i=0;i<m;i++)
        {
        b[i]=a[i];
        }
    sort(b,b+m);
    res=0;
    br=n;
    while(br>0)
        {
        br--;
        for(i=0;i<m;i++)
            {
            if(b[i]!=0)
                {
                g=b[i];
                b[i]--;
                break;
                }
            }
        res+=g;
        for(i=0;i<m;i++)
            {
            if(b[i]==g)
                {
                br--;
                res+=b[i];
                b[i]--;
                if(br==0)break;
                }
            if(b[i]!=g && b[i]!=0)break;
            }
        sort(b,b+m);
        }
    printf("%d\n",res);
    return 0;
    }