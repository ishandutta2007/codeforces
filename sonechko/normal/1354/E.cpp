#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 5000 + 11;

vector<int> v1[N],v2[N];
int k;
vector<int> v[N];
int dp[N][N];
int ans[N];
int use[N];

void dfs(int l, int t)
{
    use[l]=t;
    if (t==1) v1[k].pb(l); else v2[k].pb(l);
    for (int j=0; j<v[l].size(); j++)
    {
        int to=v[l][j];
        if (use[to]==0) dfs(to,3-t); else
        if (use[to]==use[l])
        {
            cout<<"NO\n";
            exit(0);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    for (int i=1; i<=n; i++)
        if (use[i]==0)
    {
        k++;
        dfs(i,1);
    }
    dp[0][0]=1;
    for (int i=1; i<=k; i++)
    {
        for (int ks=0; ks<=n; ks++)
            if (dp[i-1][ks]==1)
        {
            dp[i][ks+v1[i].size()]=1;
            dp[i][ks+v2[i].size()]=1;
        }
    }
    if (dp[k][n1+n3])
    {
        cout<<"YES\n";
        int ks=n1+n3;
        for (int i=k; i>=1; i--)
        {
            if (ks>=v1[i].size()&&dp[i-1][ks-v1[i].size()])
            {
                for (int j=0; j<v1[i].size(); j++)
                {
                    if (n1>0) {n1--; ans[v1[i][j]]=1;} else
                        {
                            n3--; ans[v1[i][j]]=3;
                        }
                }
                for (int j=0; j<v2[i].size(); j++)
                {
                    n2--;
                    ans[v2[i][j]]=2;
                }
                ks-=v1[i].size();
            } else
            {
                for (int j=0; j<v2[i].size(); j++)
                {
                    if (n1>0) {n1--; ans[v2[i][j]]=1;} else
                        {
                            n3--; ans[v2[i][j]]=3;
                        }
                }

                for (int j=0; j<v1[i].size(); j++)
                {
                    n2--;
                    ans[v1[i][j]]=2;
                }
                ks-=v2[i].size();
            }
        }
        for (int i=1; i<=n; i++)
            cout<<ans[i];
        cout<<endl;
    } else
    if (dp[k][n2])
    {
        cout<<"YES\n";
        int ks=n2;
        for (int i=k; i>=1; i--)
        {
            if (ks>=v2[i].size()&&dp[i-1][ks-v2[i].size()])
            {
                for (int j=0; j<v1[i].size(); j++)
                {
                    if (n1>0) {n1--; ans[v1[i][j]]=1;} else
                        {
                            n3--; ans[v1[i][j]]=3;
                        }
                }
                for (int j=0; j<v2[i].size(); j++)
                {
                    n2--;
                    ans[v2[i][j]]=2;
                }
                ks-=v2[i].size();
            } else
            {
                for (int j=0; j<v2[i].size(); j++)
                {
                    if (n1>0) {n1--; ans[v2[i][j]]=1;} else
                        {
                            n3--; ans[v2[i][j]]=3;
                        }
                }
                for (int j=0; j<v1[i].size(); j++)
                {
                    n2--;
                    ans[v1[i][j]]=2;
                }
                ks-=v1[i].size();
            }
        }
        for (int i=1; i<=n; i++)
            cout<<ans[i];
        cout<<endl;

    } else cout<<"NO\n";

}