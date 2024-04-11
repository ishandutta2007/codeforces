#include<iostream>
# include <cstring>
#include <algorithm>
#include <stdio.h>
#include<map>
using namespace std;
int first[10000];
int last[10000];
int main()
{
    int n,m;
    cin>>n>>m;
    int l=0;
    for (int i=0;i<n;i++)
    {
        first[i]=1000000;
        for (int j=0;j<m;j++)
        {
            char x;
            cin>>x;
            if (x=='W')
            {
                last[i]=j;
                l=i;
                first[i]=min(first[i],j);
            }
        }
    }
    int ans=l;
    int cur=0;
    for (int i=0;i<n;i++)
    {
        if (i%2==0)
        {
            if (i<n-1 && max(last[i],last[i+1])>cur)
            {
                ans+=max(last[i],last[i+1])-cur;
                cur=max(last[i],last[i+1]);
            }
            else if (last[i]>cur)
            {
                ans+=last[i]-cur;
                cur=last[i];
            }
        }
        else
        {
            if (i<n-1 && cur>min(first[i],first[i+1]))
            {
                ans+=cur-min(first[i],first[i+1]);
                cur=min(first[i],first[i+1]);
            }
            else if (cur>first[i])
            {
                ans+=cur-first[i];
                cur=first[i];
            }
        }
    }
    cout<<ans<<endl;
}