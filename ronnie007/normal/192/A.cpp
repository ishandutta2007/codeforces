#include<iostream>
#include<stdio.h>
using namespace std;


long long n;
long long a[250000];


int main()
    {
    scanf("%I64d",&n);
    //if(n==1)
        //{
        //printf("NO\n");
        //return 0;
        //}
    long long i,l,r;
    long long sz=0;
    n=n*2;
    for(i=1;i*i<n;i++)
        {
        //cout<<"here\n";
        a[i]=i*i+i;
        sz=i;
        }

    long long left=0;
    long long mid=0;
    for(i=1;i*i<n;i++)
        {
        left=n-a[i];
        l=0;
        r=sz;
        while(l<r)
            {
            mid=(l+r)/2;
            if(a[mid]<left)l=mid+1;
            else r=mid;
            }
        if(a[l]==left && l!=0)
            {
            //cout<<l<<"\n";
            printf("YES\n");
            return 0;
            }
        }
    printf("NO\n");
    return 0;
    }