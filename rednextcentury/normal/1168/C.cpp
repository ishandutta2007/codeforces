#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[1000000];
int nxt[500000][21];
int last[100];
int main()
{
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    int n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=n;i>=1;i--)
    {
        for (int j=0;j<20;j++)
            nxt[i][j]=((1<<j)&a[i])?i:n+1;
        for (int j=0;j<20;j++)
        {
            if (((1<<j)&a[i]))
            {
                if (last[j]!=0)
                    for(int k=0;k<20;k++)
                        nxt[i][k]=min(nxt[i][k],nxt[last[j]][k]);
                last[j]=i;
            }
        }
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        int best=n+1;
        for (int j=0;j<20;j++)
            if ((1<<j)&a[r])
                best=min(best,nxt[l][j]);
        if (best<=r)
            cout<<"Shi"<<endl;
        else cout<<"Fou"<<endl;
    }
}