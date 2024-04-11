#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 3e6 + 11;

pair<int,int> kol[N];
int a[N],b[N];
vector<int> num[N];
bool use[N];
int k;
int col[N];
vector<int> v[N];

void dfs(int l)
{
    use[l]=1;
    int p=0,c=0;
    for (int j=0; j<num[l].size(); j++)
        {
            int x=num[l][j];
            if (col[x]!=0) p=col[x];
        }
    for (int j=0; j<num[l].size(); j++)
    {
        int x=num[l][j];
        if (col[x]!=0) {} else
        {
            c++;
            if (c==p) c++;
            col[x]=c;
            k=max(k,c);
        }
    }
    for (int j=0; j<v[l].size(); j++)
        if (use[v[l][j]]==0) dfs(v[l][j]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
        kol[l].ff++;
        kol[r].ff++;
        a[i]=l;
        b[i]=r;
        num[l].pb(i);
        num[r].pb(i);
    }
    for (int i=1; i<=n; i++)
        kol[i].ss=i;
    sort(kol+1,kol+n+1);
    for (int i=n-m+1; i<=n; i++)
        use[kol[i].ss]=1;
    for (int i=1; i<=n; i++)
        if (use[i]==0) dfs(i);
    k=max(k,1);
    cout<<k<<endl;
    for (int i=1; i<n; i++)
        if (col[i]==0) cout<<1<<" "; else cout<<col[i]<<" ";
    cout<<endl;
}