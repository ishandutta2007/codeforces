#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N = 500 + 11;
int a[N][N],ans[1000000],use[1000000];
vector<int> v;
int main()
{
    int n,m;
    cin>>n>>m;
    use[1]=1;
    for (int i=2; i<=200000; i++)
        if (use[i]==0)
    {
        v.pb(i);
        for (ll j=1LL*i*i; j<=200000; j+=i)
        use[j]=1;
    }
    ans[0]=1;
    for (int i=0; i<v.size(); i++)
    {
        int k=v[i];
        while (ans[k]==0)
        {
            ans[k]=v[i];
            k--;
        }
    }
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        cin>>a[i][j];
    }
    int res=10000000;
    for (int i=1; i<=n; i++)
    {
        int ans1=0;
        for (int j=1; j<=m; j++)
            ans1+=ans[a[i][j]]-a[i][j];
        res=min(res,ans1);
    }

    for (int j=1; j<=m; j++)
    {
        int ans1=0;
        for (int i=1; i<=n; i++)
            ans1+=ans[a[i][j]]-a[i][j];
        res=min(res,ans1);
    }
    cout<<res<<endl;
}