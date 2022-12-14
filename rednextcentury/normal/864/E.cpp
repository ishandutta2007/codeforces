#include<bits/stdc++.h>
using namespace std;
struct item
{
    int t,d,p,id;
};
bool operator<(item a,item b)
{
    if (a.d==b.d)
        return a.t<b.t;
    return a.d<b.d;
}
int best[101][2001];
int n;
item a[1000];
int dp[101][2001];
bool vis[101][2001];
int DP(int i,int t)
{
    if (i==n)
        return 0;
    if (vis[i][t])return dp[i][t];
    vis[i][t]=1;
    int &ret=dp[i][t];
    int c1=DP(i+1,t);
    int c2=-1000000;
    if (t+a[i].t<a[i].d)
        c2=DP(i+1,t+a[i].t)+a[i].p;
    return ret=max(c1,c2);
}
vector<int> vec;
int Get(int i,int t)
{
    if (i==n)return -1;
    if (t+a[i].t>=a[i].d)
    {
        Get(i+1,t);
    }
    else
    {
        if (DP(i+1,t)>DP(i+1,t+a[i].t)+a[i].p)
            Get(i+1,t);
        else
        {
            vec.push_back(i);
            Get(i+1,t+a[i].t);
        }
    }
}
int main()
{
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i].t>>a[i].d>>a[i].p,a[i].id=i+1;
    sort(a,a+n);
    cout<<DP(0,0)<<endl;
    Get(0,0);
    cout<<vec.size()<<endl;
    for (int i=0;i<vec.size();i++)
        cout<<a[vec[i]].id<< ' ';
    cout<<endl;
}