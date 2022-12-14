#include<bits/stdc++.h>
using namespace std;
int ret[1000002][10];
int G[1000005];
int g(int x)
{
    if (x<10){
        G[x]=x;
        return G[x];
    }
    int y=x;
    int ret=1;
    while(x)
    {
        if (x%10)
            ret*=x%10;
        x/=10;
    }
    G[y]=G[ret];
    return G[y];
}
int main()
{
    ios_base::sync_with_stdio(0);
   for (int i=1;i<=1000000;i++)
   {
       int x = g(i);
       ret[i][x]++;
       for (int j=1;j<=9;j++)
       {
           ret[i][j]+=ret[i-1][j];
       }
   }
   int q;
   cin>>q;
   while(q--)
   {
       int l,r,k;
       cin>>l>>r>>k;
       cout<<ret[r][k]-ret[l-1][k]<<endl;
   }
}