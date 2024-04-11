#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

bool use[N];
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n*2; i++)
        cin>>a[i];
    vector<pair<int,int> > vv;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        vv.pb(mp(l,r));
    }
    int t;
    cin>>t;
    if (t==1)
    {
        for (int i=1; i<=2*n; i++)
            if (i%2==1)
        {
            int p=0;
            for (int j=0; j<vv.size(); j++)
                if (use[vv[j].ff]==0&&use[vv[j].ss]==0)
            {
                p=1;
                if (a[vv[j].ff]>a[vv[j].ss])
                {
                    cout<<vv[j].ff<<endl;
                    use[vv[j].ff]=1;
                } else
                {
                    cout<<vv[j].ss<<endl;
                    use[vv[j].ss]=1;
                }
                break;
            }
            if (p==0)
            {
                int t=0;
                for (int i=1; i<=n*2; i++)
                    if (use[i]==0&&a[i]>a[t]) t=i;
                cout<<t<<endl;
                use[t]=1;
            }
        } else
        {
            int x;
            cin>>x;
            use[x]=1;
        }
    } else
    {
        for (int i=1; i<=2*n; i++)
            if (i%2==0)
        {
            int p=0;
            for (int j=0; j<vv.size(); j++)
                if (use[vv[j].ff]==1&&use[vv[j].ss]==0)
                {
                    p=1;
                    cout<<vv[j].ss<<endl;
                    use[vv[j].ss]=1;
                    break;
                } else
                if (use[vv[j].ss]==1&&use[vv[j].ff]==0)
                {
                    p=1;
                    cout<<vv[j].ff<<endl;
                    use[vv[j].ff]=1;
                    break;
                }
            for (int j=0; j<vv.size(); j++)
                if (p==0&&use[vv[j].ff]==0&&use[vv[j].ss]==0)
                {
                    p=1;
                    if (a[vv[j].ff]>a[vv[j].ss])
                    {
                        cout<<vv[j].ff<<endl;
                        use[vv[j].ff]=1;
                    } else
                    {
                        cout<<vv[j].ss<<endl;
                        use[vv[j].ss]=1;
                    }
                    break;
                }
            if (p==0)
            {
                int t=0;
                for (int i=1; i<=n*2; i++)
                    if (use[i]==0&&a[i]>a[t]) t=i;
                cout<<t<<endl;
                use[t]=1;
            }
        } else
        {
            int x;
            cin>>x;
            use[x]=1;
        }
    }
}