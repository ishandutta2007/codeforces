#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N = 300 + 11;
char a[N][N];
int n,k,use[N],aa[N];
vector<int> v[N];
int d[N];
void dfs(int l)
{
    use[l]=k;
    v[k].pb(l);
    for (int i=1; i<=n; i++)
    if (use[i]==0&&(a[l][i]=='1'||a[i][l]=='1')) dfs(i);
}
int main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>aa[i];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            cin>>a[i][j];
    for (int i=1; i<=n; i++)
    if (use[i]==0) {k++; dfs(i);}
    for (int i=1; i<=k; i++)
    {
        for (int j=0; j<v[i].size(); j++)
            v[i][j]=aa[v[i][j]];
        sort(v[i].begin(),v[i].end());
    }
    for (int i=1; i<=n; i++)
    {
        int p=use[i];
        aa[i]=v[p][d[p]];
        d[p]++;
        cout<<aa[i]<<" ";
    }
    cout<<endl;
}