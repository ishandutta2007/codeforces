#include<bits/stdc++.h>
using namespace std;
long long dp[20000];
int ret[20000];
int n;
void add(int x)
{
    for (int i=n;i>=x;i--)
        dp[i]+=dp[i-x];
    for (int i=x;i<=n;i++)
    {
        if (dp[i])ret[i]=1;
    }
}
void rem(int x)
{
    for (int i=x;i<=n;i++)
        dp[i]-=dp[i-x];
    for (int i=x;i<=n;i++)
    {
        if (dp[i])ret[i]=1;
    }
}
multiset<pair<int,pair<int,int> > > s;
int main()
{
    dp[0]=1;
    int q;
    cin>>n>>q;
    for (int i=0;i<q;i++)
    {
        int l,r,x;
        cin>>l>>r>>x;
        s.insert(make_pair(l,make_pair(0,x)));
        s.insert(make_pair(r,make_pair(1,x)));
    }
    while(!s.empty())
    {
        pair<int,pair<int,int> > p = *s.begin();
        s.erase(s.begin());
        if (p.second.first==0)
            add(p.second.second);
        else
            rem(p.second.second);
    }
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        if (ret[i])ans++;
    }
    cout<<ans<<endl;
    for (int i=1;i<=n;i++)
    {
        if (ret[i])
            cout<<i<<' ';
    }
}