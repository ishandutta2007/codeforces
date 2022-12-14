#include <bits/stdc++.h>
using namespace std;
int mod=998244353;
int x[1000000];
int y[1000000];
int n;
map<int,pair<int,int> > mn,mx;
set<int> s;
long long Move(int &X,int &Y,int x1,int y1)
{
    long long sol=0;
    sol+=abs(X-x1);
    sol+=abs(Y-y1);
    X=x1,Y=y1;
    return sol;
}
long long dp[1000001][2];
int a[1000000];
pair<int,int> L[1000000];
pair<int,int> R[1000000];
long long solve(int i,int j,int xx,int yy)
{
    if (i==s.size())
        return 0;
    if (dp[i][j]!=-1)return dp[i][j];
    // 0
    int X=xx,Y=yy;
    long long sol=0;
    sol+=Move(X,Y,L[i].first,L[i].second);
    sol+=Move(X,Y,R[i].first,R[i].second);
    dp[i][j]=solve(i+1,0,X,Y)+sol;
    // 1
    sol=0;
    X=xx,Y=yy;
    sol+=Move(X,Y,R[i].first,R[i].second);
    sol+=Move(X,Y,L[i].first,L[i].second);
    dp[i][j]=min(dp[i][j],solve(i+1,1,X,Y)+sol);
    return dp[i][j];
}
int main()
{
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for (int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
        pair<int,int> p = {x[i],-y[i]};
        int l = max(x[i],y[i]);
        if (mn.find(l)==mn.end())
            mn[l]=p;
        else
            mn[l]=min(mn[l],p);
        if (mx.find(l)==mx.end())
            mx[l]=p;
        else
            mx[l]=max(mx[l],p);
        s.insert(l);
    }
    int i=0;
    for(set<int>::iterator it=s.begin();it!=s.end();it++)
    {
        a[i] = *it;
        L[i] = mn[*it];
        R[i] = mx[*it];
        i++;
    }
    cout<<solve(0,0,0,0)<<endl;
}