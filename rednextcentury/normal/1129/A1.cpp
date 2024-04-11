#include<bits/stdc++.h>
using namespace std;
int cur;
int n,m;
int dist(int a,int b)
{
    if (b>=a)return b-a;
    else return b+n-a;
}
int worst[1000000];
int num[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        worst[i]=1e9;
    for (int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        num[a]++;
        worst[a]=min(worst[a],dist(a,b));
    }
    for (int i=1;i<=n;i++)
    {
        long long mx=0;
        for (int j=1;j<=n;j++)
        {
            if (num[j]==0)continue;
            long long ff=dist(i,j)+n*1LL*(num[j]-1)+worst[j];
            mx=max(mx,ff);
        }
        cout<<mx<<' ';
    }
}