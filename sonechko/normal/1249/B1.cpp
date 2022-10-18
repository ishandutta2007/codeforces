#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int use[N],p[N],ans[N];
vector<int> v;

void dfs(int l)
{
    use[l]=1;
    v.pb(l);
    if (use[p[l]]==0) dfs(p[l]);
}

void up()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>p[i];
        use[i]=0;
    }
    for (int i=1; i<=n; i++)
        if (use[i]==0)
    {
        v.clear();
        dfs(i);
        for (int j=0; j<v.size(); j++)
            ans[v[j]]=v.size();
    }
    for (int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
        cout<<"\n";
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    while (q--) up();
}