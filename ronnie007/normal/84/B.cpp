#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int n;
    int a[100007];
    int i;
    long long ans=0;
    int br=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        }
    br=1;
    for(i=1;i<n;i++)
        {
        if(a[i]==a[i-1])
            {
            ans+=br;
            br++;
            }
        else
            {
            ans+=br;
            br=1;
            }
        }
    ans+=br;
    printf("%I64d\n",ans);
    return 0;
    }