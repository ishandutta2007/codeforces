#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define mp make_pair
#define ff first
#define ss second

const int N = 2000 + 11;

int kol[N],use[N],res[N],res1[N],iffind[N];
vector<int> fo[N],ot[N];
vector<int> rav[N];
char a[N][N];
int uses[N];
vector<int> p[N];
int num;

void dfs(int l)
{
    uses[l]=num;
    ///cout<<l<<" ";
    p[num].pb(l);
    for (int j=0; j<rav[l].size(); j++)
        if (uses[rav[l][j]]==0) dfs(rav[l][j]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        char ch;
        cin>>ch;
        a[i][j]=ch;
        if (ch=='=')
        {
            rav[i].pb(n+j);
            rav[n+j].pb(i);
        }
    }
    for (int i=1; i<=n+m; i++)
        if (uses[i]==0)
    {
        num++;
        ///cout<<num<<": ";
        dfs(i);
        ///cout<<endl;
    }
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    if (a[i][j]=='>')
    {
        int l=uses[i];
        int r=uses[n+j];
        if (l==r) {cout<<"No"; return 0;}
        fo[r].pb(l);
        kol[l]++;
        ot[l].pb(r);
    } else
    if (a[i][j]=='<')
    {
        int l=uses[n+j];
        int r=uses[i];
        if (l==r) {cout<<"No"; return 0;}
        fo[r].pb(l);
        kol[l]++;
        ot[l].pb(r);
    }
    for (int iii=1; iii<=num; iii++)
    {
        int g=0;
        for (int i=1; i<=num; i++)
            if (use[i]==0&&kol[i]==0) g=i;
        if (g==0) {cout<<"No"; return 0;}
        use[g]=1;
        int t=1;
        for (int i=0; i<ot[g].size(); i++)
            t=max(t,res1[ot[g][i]]+1);
        res1[g]=t;
        ///cout<<g<<"="<<t<<endl;
        for (int i=0; i<p[g].size(); i++)
            {///cout<<p[g][i]<<"=="<<t<<endl;
            res[p[g][i]]=t;}
        for (int i=0; i<fo[g].size(); i++)
            kol[fo[g][i]]--;
    }
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        int p1=i,p2=n+j;
        if (a[i][j]=='>'&&res[p1]<=res[p2]) {cout<<"No"; return 0;}
        if (a[i][j]=='<'&&res[p1]>=res[p2]) {cout<<"No"; return 0;}
        if (a[i][j]=='='&&res[p1]!=res[p2]) {cout<<"No"; return 0;}
    }
    cout<<"Yes\n";
    for (int i=1; i<=n; i++)
        cout<<res[i]<<" ";
    cout<<endl;
    for (int i=n+1; i<=n+m; i++)
        cout<<res[i]<<" ";
    cout<<endl;
}