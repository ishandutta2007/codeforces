#include<iostream>
# include <cstring>
#include <algorithm>
#include <stdio.h>
#include<vector>
using namespace std;
int n;
int tot=1;
long long nums[100000];
int solve(long long num,long long i)
{
    if (i==n)
    {
        nums[tot++]=num;
    }
    else
    {
        solve(num*10+4,i+1);
        solve(num*10+7,i+1);
    }
}
int main()
{
    int l,r;
    cin>>l>>r;
    for (int i=1;i<=10;i++)
        n=i,solve(0,0);
    nums[0]=1;
    long long ans=0;
    for (int i=1;i<tot;i++)
    {
        if (l<=nums[i-1] && r>=nums[i])
            ans+=nums[i]*(nums[i]-nums[i-1]);
        else if (l<=nums[i-1])
            ans+=nums[i]*(r-nums[i-1]);
        else if (l<=nums[i] && r>=nums[i])
            ans+=nums[i]*(nums[i]-l+1);
        else if (l>nums[i-1] && r<nums[i])
            ans+=(r-l+1)*nums[i];
        if (r<=nums[i])
            break;
    }
    if (l==1)
        ans+=4;
    cout<<ans<<endl;
}