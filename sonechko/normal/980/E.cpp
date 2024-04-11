#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
#define y1 dhnfg
#define ld long double

const int N = 2e6 + 11;

vector<int> v[N];
bool use[N];
int d[20][N];
int st[22];

void dfs(int l, int prr)
{
    d[0][l]=prr;
    for (int j=0; j<v[l].size(); j++)
        if (prr!=v[l][j]) dfs(v[l][j],l);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    st[0]=1;
    for (int i=1; i<=20; i++)
        st[i]=st[i-1]*2;
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    k=n-k;
    dfs(n,0);
    for (int j=1; j<=19; j++)
    for (int i=1; i<=n; i++)
    d[j][i]=d[j-1][d[j-1][i]];
    use[n]=1;
    k--;
    for (int i=n-1; i>=1; i--)
    {
        if (use[i]) continue;
        int g=i;
        int p=1;
        for (int j=19; j>=0; j--)
            if (d[j][g]!=0&&use[d[j][g]]==0)
            {
                p+=st[j];
                g=d[j][g];
            }
        if (p<=k)
        {
            int g=i;
            while (use[g]==0)
            {
                use[g]=1;
                k--;
                g=d[0][g];
            }
        }
    }
    for (int i=1; i<=n; i++)
        if (use[i]==0) cout<<i<<" ";
}