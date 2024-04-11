#include <bits/stdc++.h>
using namespace std;
vector<int> vec[2000001];
int m;
int ret[2000001];
long long tot=0;
void Get(int l1,int r1,int l2,int r2)
{
    if (l2==1000000000)
    {
        ret[1]++;
        ret[m-r1+2]--;
        ret[m-l1+2]++;
        ret[m+1]--;
    }
    else
    {
        if (r2<l1)
        {
            ret[m-l1+2]++;
            ret[m-r2+2]--;
        }
    }
}
void solve(int l,int r,int x)
{
    while(l<=r && vec[l].size()<=x)
        l++;
    if (l>r)
        return;
    tot++;
    int mn1=vec[l][x],mn2=1000000000;
    int mx1=vec[l][x],mx2=0;
    bool is=0,is2=0;
    for (int i=l+1;i<=r;i++)
    {
        if (x>=vec[i].size())
        {
            tot=1000000000;
            return;
        }
        if (vec[i][x]<vec[i-1][x] && is)
            is2=1;
        if (vec[i][x]<vec[i-1][x])
            is=1;
        if (!is)
            mn1=min(mn1,vec[i][x]),mx1=max(mx1,vec[i][x]);
        else
            mn2=min(mn2,vec[i][x]),mx2=max(mx2,vec[i][x]);
    }
    if (is2){
        tot=1000000000;
        return;
    }
    Get(mn1,mx1,mn2,mx2);
    int last=l;
    for (int i=l;i<=r;i++)
    {
        if (vec[i][x]!=vec[last][x])
        {
            solve(last,i-1,x+1);
            last=i;
        }
    }
    solve(last,r,x+1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        while(x--)
        {
            int y;
            cin>>y;
            vec[i].push_back(y);
        }
    }
    solve(0,n-1,0);
    int num=0;
    for (int i=1;i<=m;i++)
    {
        num+=ret[i];
        if (num==tot){
            cout<<i-1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}