#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 2e5 + 11;

vector<int> v[N];
int num[N],ord[N],kol,tout[N];

void dfs(int l)
{
    kol++;
    ord[kol]=l;
    num[l]=kol;
    for (int j=0; j<v[l].size(); j++)
        dfs(v[l][j]);
    tout[l]=kol;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q;
    cin>>n>>q;
    for (int i=2; i<=n; i++)
    {
        int p;
        cin>>p;
        v[p].pb(i);
    }
    for (int i=1; i<=n; i++)
        sort(v[i].begin(),v[i].end());
    dfs(1);
    /**
    for (int i=1; i<=n; i++)
        cout<<ord[i]<<" ";
    cout<<endl;
    **/
    for (int i=1; i<=q; i++)
    {
        int l,r;
        cin>>l>>r;
        if (num[l]+r-1>n||tout[l]<num[l]+r-1) cout<<-1<<"\n"; else
        cout<<ord[num[l]+r-1]<<"\n";
    }
}