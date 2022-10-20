#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;


int used[100007];
int used1[100007];

int main()
    {
    int n;
    int a[100007];
    int m;
    int b[100007];
    long long br1=0;
    long long br2=0;
    int i,j;

    scanf("%d",&n);
    for(i=0;i<=n;i++)
        {
        used[i]=0;
        used1[i]=0;
        }
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        if(used[a[i]]==0 && a[0]!=a[i])used[a[i]]=i;
        used1[a[i]]=n-i-1;
        }
    scanf("%d",&m);
    for(i=0;i<m;i++)
        {
        scanf("%d",&b[i]);
        }
    br1=0;
    br2=0;
    for(i=0;i<m;i++)
        {
        br1+=used[b[i]]+1;
        br2+=used1[b[i]]+1;
        }
    cout<<br1<<" "<<br2<<"\n";
    return 0;
    }