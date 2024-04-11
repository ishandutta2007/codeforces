#include <bits/stdc++.h>
using namespace std;
long long num[1000];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        long long x;
        cin>>x;
        for (int j=0;j<=30;j++)
        {
            if (x==(1<<j))
                num[j]++;
        }
    }
    for (int i=0;i<m;i++)
    {
        long long x;
        cin>>x;
        int ret=0;
        for (long long j=30;j>=0;j--)
        {
            if (x>=(1<<j))
            {
                int op = min(num[j],x/(1LL<<j));
                x-=op*(1LL<<j);
                ret+=op;
            }
        }
        if (x==0)cout<<ret<<endl;
        else cout<<-1<<endl;
    }
}