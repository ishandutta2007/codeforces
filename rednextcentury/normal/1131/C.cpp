#include <bits/stdc++.h>
using namespace std;
int a[1000000];
vector<int> pos;
vector<int> ret;
int n;
void print()
{
    for (auto x:ret)
        cout<<x<<' ';
}
bool vis[101];
bool can(int x)
{
    memset(vis,0,sizeof(vis));
    ret.clear();
    ret.push_back(a[0]);
    int last=a[0];
    int idx=0;
    vis[0]=1;
    for (int i=1;i<n;i++)
    {
        if (a[i]-last>x)
        {
            if (i-1 != idx)
                vis[i-1]=1,ret.push_back(a[i-1]),last=a[i-1],idx=i-1;
            else break;
        }
    }
    for (int i=n-1;i>=0;i--)
        if (!vis[i])ret.push_back(a[i]);
    int mx=abs(ret[ret.size()-1]-ret[0]);
    for (int i=1;i<ret.size();i++)
        mx=max(mx,abs(ret[i]-ret[i-1]));
    if (mx<=x)
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        for (int j=0;j<i;j++)
            pos.push_back(abs(a[i]-a[j]));
    }
    sort(a,a+n);
    sort(pos.begin(),pos.end());
    for (auto x:pos)
    {
        if (can(x)){
            print();
            return 0;
        }
    }
}