#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int n;
    int a;
    int br=0;
    int mn=1000000009;
    int ind=-1;
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        scanf("%d",&a);
        if(a==mn)br++;
        if(a<mn)
            {
            mn=a;
            ind=i+1;
            br=1;
            }
        }
    if(br>1)
        {
        printf("Still Rozdil\n");
        }
    else
        {
        printf("%d\n",ind);
        }
    return 0;
    }