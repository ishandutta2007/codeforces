#include <bits/stdc++.h>
using namespace std;
int F[3000000][2];
int a[1000005];
int BITS=21;
void add(int state,int i)
{
    if (i>F[state][0])
    {
        swap(F[state][0],F[state][1]);
        F[state][0]=i;
    }
    else if (i>F[state][1])
        F[state][1]=i;
}
int tot = (1<<BITS);
int best(int num)
{
    return F[tot-1-num][1];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        add(tot-a[i]-1,i);
    }
    for (int i=0;i<=BITS;i++)
    {
        for (int j=0;j<tot;j++)
        {
            if (j&(1<<i))
            {
                add(j,F[j-(1<<i)][0]);
                add(j,F[j-(1<<i)][1]);
            }
        }
    }
    int ans=0;
    for (int i=1;i+2<=n;i++)
    {
        int ret=0;
        for (int j=BITS-1;j>=0;j--)
        {
            if ((1<<j)&a[i])continue;
            ret+=(1<<j);
            if (best(ret)>i)continue;
            ret-=(1<<j);
        }
        ans=max(ans,ret|a[i]);
    }
    cout<<ans<<endl;
}