#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int temp[MAXN],valid[MAXN],n,k,q;
int main()
{
    scanf("%d %d %d",&n,&k,&q);
    memset(temp,0,sizeof(temp));
    memset(valid,0,sizeof(valid));
    for(int i=0;i<n;i++)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        temp[l]++;
        temp[r+1]--;
    }
    int s=0;
    for(int i=1;i<=200000;i++)
    {
        s+=temp[i];
        if(s>=k) valid[i]=valid[i-1]+1; else valid[i]=valid[i-1];
    }
    for(int i=0;i<q;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%d\n",valid[y]-valid[x-1]);
    }
    return 0;
}