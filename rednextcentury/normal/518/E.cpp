# include <iostream>
# include<algorithm>
#include <stdio.h>
# include <cstdlib>
using namespace std;
long a[1000000];
bool no[1000000];
char curnum[1000];
bool vis[1000000];
    long long n,k;
long long calc(long long st,long long en,long long num)
{
    if (en<=1)
        return en-num;
    if (st>=-1)
        return st+1;
    long long x=-num/2;
    if (x<=st)
        x+=(st-x+1);
    if (x+num-1>=en)
        x=en-num;
    return x;
}
void fil(long long st,long long en,long long j)
{
    for (long long i=st;i<=en;i+=k)
        if (no[i])
            a[i]=j,j++;
}
int main()
{
    cin>>n>>k;
    for (long long i=0;i<n;i++)
    {
        cin>>curnum;
        if (curnum[0]=='?')
        {
            no[i]=1;
        }
        else
            a[i]=atoi(curnum);
    }
    for (long long i=0;i<n;i++)
    {
        if (vis[i]) continue;
        long long num=0;
        long long last=3000000000;
        last*=-1;
        long long idx=i;
        for (long long x=i;x<n;x+=k)
        {
            vis[x]=1;
            if (no[x])
                num++;
            if (no[x]==0 || x+k>=n)
            {
                if (num==0)
                {
                    idx=x;
                    last=a[x];
                    continue;
                }
                long long en=a[x];
                if (no[x]==1)
                    en=3000000000;
                if (en-last-1<num)
                {
                    cout<<"Incorrect sequence"<<endl;
                    return 0;
                }
                long long st=calc(last,en,num);
                fil(idx,x,st);
                num=0;
                idx=x;
                last=en;
            }
        }
    }
     long long sum=0;
    for (long long i=0;i<k;i++)
        sum+=a[i];
    for (long long i=k;i<n;i++)
    {
        long long last=sum;
        sum+=a[i];
        sum-=a[i-k];
        if (sum<=last)
        {
            cout<<"Incorrect sequence"<<endl;
            return 0;
        }
    }
    for (long long i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}