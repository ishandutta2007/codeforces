#include<iostream>
#include<cstring>
#include<algorithm>
#include <map>
#include<vector>
using namespace std;
int a[1000000];
int suf[1000000][2],pre[1000000][2];
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        char x;
        cin>>x;
        a[i]=x-'0';
    }
    for (int i=n;i>=1;i--)
    {
        if (a[i]==0) suf[i][1]=suf[i+1][1],suf[i][0]=suf[i][1]+1;
        else suf[i][0]=suf[i+1][0],suf[i][1]=suf[i][0]+1;
    }
    for (int i=1;i<=n;i++)
    {
        if (a[i]==0) pre[i][1]=pre[i-1][1],pre[i][0]=pre[i][1]+1;
        else pre[i][0]=pre[i-1][0],pre[i][1]=pre[i][0]+1;
    }
    int last=a[1];
    int beg=a[1];
    int ans=0;
    int len=1;
    ans=max(pre[n][0],pre[n][1]);
    for (int i=2;i<=n;i++)
    {
        if (a[i]==last)
        {
            ans=max(ans,pre[i-len-1][beg]+suf[i][last]+len);
            len=1;
            beg=a[i];
        }
        else
            len++;
        last=a[i];
    }
    ans=max(ans,pre[n-len][beg]+suf[n+1][last]+len);
    cout<<ans<<endl;
}