#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int b[1000000];
int c[1000000];
int m;
int solve(int st,int pos,int k)
{
    if (pos<=k)return 0;
    for (int i=st;i<m;i++)
        c[i-st]=b[i];
    int len=m-st;
    if (len>0)
        sort(c,c+len);
    int ret=0;
    for (int i=len-1;i>=0;i--)
    {
        pos-=c[i];
        ret+=2;
        if (pos<=k)
            return ret;
    }
    return 1000000000;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int pos=0;
    for (int i=0;i<n;i++){
        cin>>a[i];
        if (a[i]<0)k--;
        else pos++;
    }
    if (pos==n)
    {
        cout<<0<<endl;
        return 0;
    }
    int num=0;
    m=0;
    int last=0;
    for (int i=0;i<n;i++)
    {
        if (a[i]<0 &&  last>=0)
        {
            if (num>0)
                b[m++]=num;

            last=a[i];
            num=1;
        }
        else if (a[i]>=0 &&  last<0)
        {
            last=a[i];
            num=1;
        }
        else
        {
            num++;
            last=a[i];
        }
    }
    int t=num;
    int ans=n*3;
    if (a[0]>=0)
    {
        pos-=b[0];
        if (a[n-1]>=0)
        {
            ans=min(ans,solve(1,pos-t,k)+2);
            ans=min(ans,solve(1,pos-t,k-t)+1);
        }
        else
        {
            ans=min(ans,solve(1,pos,k)+1);
        }
    }
    else
    {
        if (a[n-1]>=0)
        {
            ans=min(ans,solve(0,pos-t,k)+2);
            ans=min(ans,solve(0,pos-t,k-t)+1);
        }
        else
        {
            ans=min(ans,solve(0,pos,k)+1);
        }
    }
    if (ans>n*2)
        cout<<-1<<endl;
    else
    {
        cout<<ans<<endl;
    }
}