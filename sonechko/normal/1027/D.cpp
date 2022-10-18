#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

const int N = 1e6 + 11;
const ll MOD = 998244353;

int num[N],nx[N],kk,use[N],cycl[N],a[N],ans[N];
vector<int> v;

int dfs(int i)
{
    use[i]=1;
    v.pb(i);
    if (use[nx[i]]==0)
    {
        int p=dfs(nx[i]);
        num[i]=p;
    } else
    if (use[nx[i]]==2)
    {
        num[i]=num[nx[i]];
    } else
    {
        kk++;
        num[i]=kk;
        for (int j=v.size()-1; j>=0; j--)
        {
            cycl[v[j]]=1;
            if (v[j]==nx[i]) break;
        }
    }
    v.pop_back();
    use[i]=2;
    return num[i];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        cin>>nx[i];
    for (int i=1; i<=n; i++)
        if (use[i]==0)
    {
        int c=dfs(i);
    }
    for (int i=1; i<=kk; i++)
        ans[i]=2e9;
    for (int i=1; i<=n; i++)
        if (cycl[i]) ans[num[i]]=min(ans[num[i]],a[i]);
    int res=0;
    for (int i=1; i<=kk; i++)
        res+=ans[i];
    cout<<res<<"\n";

}