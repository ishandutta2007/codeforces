#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;


int main()
    {
    int n;
    long long a[100007];
    int i,j;
    long long b[100007];
    int k;
    int l,r;
    int m;
    scanf("%d%d",&n,&k);
    b[0]=0;
    long long best=0;
    int brbest=0;
    for(i=1;i<=n;i++)
        {
        cin>>a[i];
        }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)
        {
        b[i]=b[i-1]+a[i];
        }
    for(i=1;i<=n;i++)
        {
        l=1;
        r=i;
        while(l!=r)
            {
            //if(i==4)printf("%d %d\n",l,r);
            m=(r+l)/2;
           // if(i==4)printf("%d\n",m);
            if(abs(a[i]*(i-m+1)-(b[i]-b[m-1]))<=k)
                {
                r=m;
                }
            else l=m+1;
            }
        //if(i==4)printf("%d %d\n",r,i);
        if(brbest<(i-l+1))
            {
            brbest=i-l+1;
            best=a[i];
            //printf("%d %d\n",l,i);
            }
        else if(brbest==(i-l+1))
            {
            if(best>a[i])best=a[i];
            }
        }
    cout<<brbest<<" "<<best<<"\n";
    return 0;
    }