#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
    {
    int n,k;
    int a[100007];
    int i,j,t,g;
    scanf("%d%d",&n,&k);
    int b[100007];
    int c[100007];
    int top=0;
    for(g=0;g<n;g++)
        {
        scanf("%d",&a[g]);
        if(g<k-1)b[g]=a[g];
        else
            {
            c[top]=a[g];
            top++;
            }
        }
    sort(c,c+top);
    for(i=1;i<top;i++)
        {
        if(c[i]!=c[i-1])
            {
            printf("-1\n");
            return 0;
            }
        }
    int br=k-1;
    for(i=k-2;i>=0;i--)
        {
        if(b[i]==c[0])
            {
            br--;
            }
        else break;
        }
    printf("%d\n",br);
    return 0;
    }