#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

vector<int> vv;
int n,ans;
int use[1000];
int dp[1000];

int get()
{
    int ans=0,res=0;
    for (int j=0; j<vv.size(); j++)
    {
        dp[j]=1;
        for (int p=0; p<j; p++)
            if (vv[p]<vv[j]) dp[j]=max(dp[j],dp[p]+1);
        res=max(res,dp[j]);
    }
    ans+=res;
    res=0;
    for (int j=0; j<vv.size(); j++)
    {
        dp[j]=1;
        for (int p=0; p<j; p++)
            if (vv[p]>vv[j]) dp[j]=max(dp[j],dp[p]+1);
        res=max(res,dp[j]);
    }
    ans+=res;
    return ans;
}

void rec(int l)
{
    if (l==n+1)
    {
        if (get()==7)
        {
            for (int j=0; j<vv.size(); j++)
                cout<<vv[j]<<" ";
            cout<<endl;
        }
        if (get()<ans) ans=get();
        return;
    }
    for (int j=1; j<=n; j++)
        if (use[j]==0)
    {
        use[j]=1;
        vv.pb(j);
        rec(l+1);
        vv.pop_back();
        use[j]=0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    //rec(1);
    vv.clear();
    int p=floor(sqrt(n));
    int x=n/p,m=n,c=n%p;
    for (int d=1; d<p; d++)
    {
        if (c>0) vv.pb(m-x);
        for (int i=m-x+1; i<=m; i++)
            vv.pb(i);
        if (c>0) {c--; m--;}
        m-=x;
    }
    for (int i=1; i<=m; i++)
        vv.pb(i);
    //cout<<"! "<<get()<<endl;
    for (int j=0; j<vv.size(); j++)
        cout<<vv[j]<<" ";
    cout<<endl;
}



/**

1 - 1
2 - 2 1
3 - 2 3 1
4 - 3 4 1 2
5 - 3 4 5 1 2
6 - 4 5 6 1 2 3
7 - 4 5 6 7 1 2 3
8 - 5 6 7 8 1 2 3 4
9 - 5 6 7 8 9 1 2 3 4

**/