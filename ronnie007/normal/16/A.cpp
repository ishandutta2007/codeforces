#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
    {
    int n,m;
    string a[150];
    int i,j;
    int br=0;
    cin>>n>>m;
    for(i=0;i<n;i++)
        {
        cin>>a[i];
        }
    br=1;
    for(i=1;i<m;i++)
        {
        if(a[0][i]==a[0][i-1])br++;
        }
    if(br!=m)
        {
        printf("NO\n");
        return 0;
        }
    for(j=1;j<n;j++)
        {
        if(a[j][0]==a[j-1][0])
            {
            printf("NO\n");
            return 0;
            }
        br=1;
        for(i=1;i<m;i++)
            {
            if(a[j][i]==a[j][i-1])br++;
            }
        if(br!=m)
            {
            printf("NO\n");
            return 0;
            }
        }
    printf("YES\n");
    return 0;
    }