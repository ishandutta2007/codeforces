# include <iostream>
# include <vector>
# include <stdio.h>
#include <limits.h>
#include <stack>
#include <algorithm>
using namespace std;
long long dp[40][40];
long long b[40][40];
long long a[40];
long long digit[100];
long long ret[32][32];
void Fill(long long k,long long n,bool last,long long ko)
{
int add=0;
if (n<0) n=10+n,add=10;
    for (long long j=0;j<=6;j++)
    {
        for (long long i=0;i<=j;i++)
        {
            long long now=7*i+(j-i)*4 + add;
            if (now%10==n)
            {
                if (now/10>0 && last==1)
                    continue;
                dp[k][now/10]=1;
                b[k][now/10]=ko;
            }
        }
    }
}
void GetSum(long long sum,long long k)
{
    for (long long j=0;j<=6;j++)
    {
        for (long long i=0;i<=j;i++)
        {
            long long now=7*i+(j-i)*4;
            if (now==sum)
            {
                for (long long x=0;x<j;x++)
                {
                    if (x<i)
                        ret[x][k]=7;
                    else
                        ret[x][k]=4;
                }
            }
        }
    }
}
void print(long long ar[])
{
    long long j=30;
    while(ar[j]==0 && j>=0)
        j--;
    if (j==-1)
        cout<<"0";
    else
        for (long long i=j;i>=0;i--)
            cout<<ar[i];
    cout<<' ';
}
int  main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        for (long long i=0;i<=30;i++)
        {
            for (long long j=0;j<=30;j++)
            {
                a[i]=0;
                dp[i][j]=0;
                b[i][j]=0;
                ret[i][j]=0;
            }
        }
        long long n;
        cin>>n;
        long long m=n;
        long long idx=0;
        long long h=0;
        bool last=0;
        while(m>0)
        {
            long long g=m%10;
            m/=10;
            h=g;
            digit[idx]=g;
            if (m==0)
                last=1;
            if (idx==0)
                Fill(idx,g,last,0);
            else
            {
                for (long long i=0;i<10;i++)
                {
                    if (dp[idx-1][i])
                    {
                        Fill(idx,g-i,last,i);
                    }
                }
            }

            idx++;
        }
        if (dp[idx-1][0])
        {
            long long j=idx-1;
            a[j]=0;
            while(j!=0)
            {
                a[j-1]=b[j][a[j]];
                j--;
            }
            GetSum(a[0]*10+digit[0],0);
            for (long long i=1;i<idx;i++)
            {
                GetSum(a[i]*10 + digit[i] - a[i-1] , i);
            }
            for (long long i=0;i<6;i++)
            {
                print(ret[i]);
            }
            cout<<endl;
        }
        else
            cout<<-1<<endl;
    }
}