#include<bits/stdc++.h>
#define MAXN 200300
using namespace std;
int a[MAXN],k,n;
vector<int> b[MAXN];
int main()
{
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    k=0;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        int left=-1,right=k;
        while(right-left>1)
        {
            int mid=(left+right)/2;
            if(a[mid]<x) right=mid; else left=mid;
        }
        if(right<k)
        {
            a[right]=x;
            b[right].push_back(x);
        }
        else
        {
            a[right]=x;
            k++;
            b[right].push_back(x);
        }
    }
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<b[i].size();j++)
            printf("%d ",b[i][j]);
        printf("\n");
    }
    return 0;
}