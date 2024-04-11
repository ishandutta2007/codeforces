#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int n;
    int a[50][50];
    int s1[50];
    int s2[50];
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        for(j=0;j<n;j++)
            {
            scanf("%d",&a[i][j]);
            }
        }
    for(i=0;i<n;i++)
        {
        s1[i]=0;
        s2[i]=0;
        for(j=0;j<n;j++)
            {
            s1[i]+=a[i][j];
            s2[i]+=a[j][i];
            }
        }
    int br=0;
    for(i=0;i<n;i++)
        {
        for(j=0;j<n;j++)
            {
            if(s1[i]<s2[j])
                {
                //printf("%d %d\n",i,j);
                br++;
                }
            }
        }
    printf("%d\n",br);
    return 0;
    }