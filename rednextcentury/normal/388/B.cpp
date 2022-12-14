# include <iostream>
# include<algorithm>
#include <stdio.h>
# include <cstdlib>
# include <ios>
# include <map>
using namespace std;
int pows[100];
bool used[100];
bool adj[3001][3001];
int num[1000];
int now;
int mx=1;
void add(int x)
{
    if (x==0)
    {
            adj[1][now]=adj[now][1]=1;
            int l=now;
            now++;
            for (int j=1;j<mx;j++)
            {
                adj[l][now]=adj[now][l]=1;
                l=now;
                now++;
            }
            adj[l][2]=adj[2][l]=1;
    }
    else
    {
        int l1=now;
        int l2=now+1;
        adj[1][l2]=adj[l2][1]=adj[1][l1]=adj[l1][1]=1;
        now+=2;
        int i=1;
        int nums=1;
        for (i=1;i<x;i++)
        {
            nums++;
            adj[now+1][l2]=adj[l2][now+1]=adj[now+1][l1]=adj[l1][now+1]=adj[now][l2]=adj[l2][now]=adj[now][l1]=adj[l1][now]=1;
            l1=now+1;
            l2=now;
            now+=2;
        }
        if (nums<mx)
        {
            adj[num[nums]][l1]=adj[l1][num[nums]]=adj[l2][num[nums]]=adj[num[nums]][l2]=1;
        }
        else
        adj[2][l2]=adj[l2][2]=adj[2][l1]=adj[l1][2]=1;
    }
}
int main()
{
    pows[0]=1;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tot=1;
    while(1)
    {
        pows[tot]=pows[tot-1]*2;
        tot++;
        if (pows[tot-1]>1000000000)
            break;
    }
    int k;
    cin>>k;
    k--;
    for (int i=tot-1;i>=0;i--)
    {
        if (k>=pows[i])
        {
            mx=max(mx,i);
            used[i]=1;
            k-=pows[i];
        }
    }
    now=3;
    int l=1;
    for (int i=0;i<mx;i++)
    {
        adj[l][now]=adj[now][l]=1;
        num[i]=now;
        l=now;
        now++;
    }
    adj[now-1][2]=adj[2][now-1]=1;
    for (int i=0;i<tot;i++)
    {
        if (used[i])
        {
            add(i);
        }
    }
    cout<<now-1<<endl;
    for (int i=1;i<now;i++)
    {
        for (int j=1;j<now;j++)
        {
            cout<<(adj[i][j]?'Y':'N');
        }
        cout<<endl;
    }
}