#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

vector<int> vv[N],dd[N],v[N];
int a[N];
int ans=0;

void dfs(int l, int pr)
{
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) dfs(v[l][j],l);
    for (int t=0; t<vv[l].size(); t++)
    {
        int del=vv[l][t];
        int mx1=0,mx2=0;
        for (int j=0; j<v[l].size(); j++)
            if (v[l][j]!=pr)
        {
            int to=v[l][j];
            for (int x=0; x<vv[to].size(); x++)
            if (vv[to][x]==del)
            {
                int dp=dd[to][x];
                if (dp>mx1) {mx2=mx1; mx1=dp;} else 
                if (dp>mx2) {mx2=dp;}
            }
        }
        ans=max(ans,mx1+mx2+1);
        dd[l].pb(mx1+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        int d=2;
        while (d*d<=a[i])
        {
            if (a[i]%d==0) vv[i].pb(d);
            while (a[i]%d==0)
                a[i]/=d;
            d++;
        }
        if (a[i]>1) vv[i].pb(a[i]);
    }
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    dfs(1,0);
    cout<<ans<<endl;
}