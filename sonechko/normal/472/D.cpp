#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 2000 + 11;

int a[N][N],b[N][N];
vector<pair<int,int> > v[N];
bool use[N];
vector<int> vv;

void dfs(int l)
{
    vv.pb(l);
    use[l]=1;
    for (int j=0; j<v[l].size(); j++)
        if (use[v[l][j].ff]==0) dfs(v[l][j].ff);
}

void dfs(int l, int pr, int len)
{
    b[pr][l]=len;
    use[l]=1;
    for (int j=0; j<v[l].size(); j++)
        if (use[v[l][j].ff]==0) dfs(v[l][j].ff,pr,len+v[l][j].ss);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<pair<int,pair<int,int> > > t;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        cin>>a[i][j];
        if (i==j&&a[i][j]!=0) {cout<<"NO"<<endl; return 0;}
        if (i!=j&&a[i][j]==0) {cout<<"NO"<<endl; return 0;}
        if (i>j&&a[i][j]!=a[j][i]) {cout<<"NO"<<endl; return 0;}
        if (i<j) t.pb(mp(a[i][j],mp(i,j)));
    }
    sort(t.begin(),t.end());
    for (int i=0; i<t.size(); i++)
    {
        int p=t[i].ff,l=t[i].ss.ff,r=t[i].ss.ss;
        if (b[l][r]==1) {} else
        {
            vv.clear();
            for (int j=1; j<=n; j++)
                use[j]=0;
            dfs(l);
            vector<int> v1=vv;
            vv.clear();
            for (int j=1; j<=n; j++)
                use[j]=0;
            dfs(r);
            vector<int> v2=vv;
            v[l].pb(mp(r,p));
            v[r].pb(mp(l,p));
            for (int p=0; p<v1.size(); p++)
            for (int d=0; d<v2.size(); d++)
            {
                b[v1[p]][v2[d]]=1;
                b[v2[d]][v1[p]]=1;
            }
        }
    }
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    b[i][j]=0;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
            use[j]=0;
        dfs(i,i,0);
        for (int j=1; j<=n; j++)
        if (a[i][j]!=b[i][j]) {cout<<"NO"<<endl; return 0;}
    }
    cout<<"YES"<<endl;

}