#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
    {
    int n,m;
    scanf("%d%d",&n,&m);
    int i,j;
    string a[124];
    int mx[124];
    for(i=0;i<n;i++)
        {
        cin>>a[i];
        }
    for(i=0;i<m;i++)
        {
        mx[i]=0;
        for(j=0;j<n;j++)
            {
            if(a[j][i]-'0'>mx[i])mx[i]=a[j][i]-'0';
            }
        }
    int br=0;
    for(i=0;i<n;i++)
        {
        for(j=0;j<m;j++)
            {
            if(a[i][j]-'0'==mx[j]){br++;break;}
            }
        }
    printf("%d\n",br);
    return 0;
    }