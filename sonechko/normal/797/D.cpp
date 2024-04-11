#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e5 + 17;
int l1[N],r1[N],a[N],use[N];
map<int,bool> mt;
void dfs(int v, int l, int r)
{
    if (a[v]>l&&a[v]<r) mt[a[v]]=1;
    if (l1[v]!=-1) dfs(l1[v],l,min(r,a[v]));
    if (r1[v]!=-1) dfs(r1[v],max(l,a[v]),r);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i]>>l1[i]>>r1[i];
        if (l1[i]!=-1) use[l1[i]]=1;
        if (r1[i]!=-1) use[r1[i]]=1;
    }
    for (int i=1; i<=n; i++)
    if (use[i]==0) dfs(i,-1,1e9+1);
    int ans=0;
    for (int i=1; i<=n; i++)
        if (mt[a[i]]==0) ans++;
    cout<<ans<<endl;
}