#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define pb push_back
#define ss second
#define mp make_pair

const int N = 2e5 + 11;

int a[N];
vector<int> v[N];

void up()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        v[i].clear();
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        v[a[i]].pb(i);
    }
    int ans=n;
    for (int i=1; i<=n; i++)
        if (v[i].size()>0)
    {
        int res=0;
        int last=0;
        for (int j=0; j<v[i].size(); j++)
        {
            int pos=v[i][j];
            if (pos-last>1) res++;
            last=pos;
        }
        if (last<n) res++;
        ans=min(ans,res);
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}