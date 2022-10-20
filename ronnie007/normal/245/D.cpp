#include<iostream>
#include<stdio.h>
using namespace std;


    int a[105];
int main()
    {
    int i,j;
    int n;
    int c;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        for(j=0;j<n;j++)
            {
            cin>>c;
            if(c!=-1)
                {
                a[i]=a[i]|c;
                a[j]=a[j]|c;
                }
            }
        }
    for(i=0;i<n;i++)
        {
        printf("%d ",a[i]);
        }
    printf("\n");
    return 0;
    }