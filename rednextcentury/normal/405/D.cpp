# include<iostream>
#include<bits/stdc++.h>
#define EPS 1e-6
#include <stdio.h>
using namespace std;
int a[1000000];
bool vis[1000001];
vector<int> ret;
inline int op(int x)
{
    return 1000000-x+1;
}
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]),vis[a[i]]=1;
    int x=0;
    for (int i=0;i<n;i++)
    {
        if (vis[op(a[i])] && a[i]>op(a[i]))
            continue;
        if (!vis[op(a[i])])
            vis[op(a[i])]=1,ret.push_back(op(a[i]));
        else
            x++;
    }
    for (int i=1;i<=1000000;i++)
    {
        if(x==0)
            break;
        if (!vis[i] && !vis[op(i)])
            ret.push_back(i),ret.push_back(op(i)),x--;
    }
    printf("%d\n",ret.size());
    for (int i=0;i<ret.size();i++)
        printf("%d ",ret[i]);
    printf("\n");
}