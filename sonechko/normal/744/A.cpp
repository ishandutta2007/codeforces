
#include<bits/stdc++.h>

using namespace std;
const int N = 1000 + 10;
#define f first
#define s second
#define mp make_pair
#define pb push_back
vector<int> v[N];
int use[N],use1[N],pref;
void dfs(int l, int k)
{
    use[l]=k;
    pref++;
    for (int i=0; i<v[l].size(); i++)
        if (use[v[l][i]]==0) dfs(v[l][i],k);
}
int main()
{
    ios_base::sync_with_stdio(); cin.tie(); cout.tie();
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=k; i++)
    {
        int p;
        cin>>p;
        use1[p]=1;
    }
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    int kk=0,ans1=0,res=0,ans=0;
    for (int i=1; i<=n; i++)
        if (use[i]==0)
    {
        kk++;
        pref=0;
        dfs(i,kk);
        int t=0;
        for (int j=1; j<=n; j++)
            if (use[j]==kk&&use1[j]==1)
            {
                t=1;
            }
        if (t==0) ans1+=pref; else
        {
            ans+=pref*(pref-1)/2;
            res=max(res,pref);
        }
    }
    cout<<ans+(ans1*(ans1-1))/2+ans1*res-m<<endl;
}