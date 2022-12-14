#include <bits/stdc++.h>
using namespace std;
long long num[10000];
long long ret[10000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int pp = n/m;
    int x=n%m;
    for (int i=0;i<m;i++)
    {
        num[i]=pp;
    }
    int cur=x;
    while(x--)
    {
        num[cur]++;
        cur--;
        if (cur<0)cur=m-1;
    }
    for (int i=0;i<m;i++)
    {
        ret[(i*i)%m]+=num[i];
    }
    long long ans=0;
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (i+j==m || i+j==0)
                ans+=ret[i]*ret[j];
        }
    }
    cout<<ans<<endl;
}