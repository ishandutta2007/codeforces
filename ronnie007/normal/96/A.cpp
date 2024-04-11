#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int n;
    string a;
    cin>>a;
    int i,j;
    n=a.size();
    if(n<7)
        {
        printf("NO");
        return 0;
        }
    int fl=0;
    for(i=0;i<n-6;i++)
        {
        fl=0;
        for(j=0;j<7;j++)
            {
            if(a[i+j]!=a[i]){fl=1;break;}
            }
        if(fl==0)
            {
            printf("YES\n");
            return 0;
            }
        }
    printf("NO\n");
    return 0;
    }