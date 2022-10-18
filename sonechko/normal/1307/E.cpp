#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 5000 + 11;
const int MOD = 1e9 + 7;

bool use[N][N];
int k1[N][N],k2[N][N];
int s[N],a[N],b[N];
int u1[N],u2[N];
vector<int> v[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        cin>>s[i];
        for (int j=1; j<=n; j++)
            k1[i][j]=k1[i-1][j];
        k1[i][s[i]]++;
    }
    for (int i=n; i>=1; i--)
    {
        for (int j=1; j<=n; j++)
            k2[i][j]=k2[i+1][j];
        k2[i][s[i]]++;
    }
    for (int i=1; i<=m; i++)
    {
        cin>>a[i]>>b[i];
        use[a[i]][b[i]]=1;
        v[a[i]].pb(b[i]);
    }
    int ans=0;
    ll ans2=0;
    for (int i=0; i<=n; i++)
    {
        int res=0;
        for (int j=1; j<=m; j++)
            use[a[j]][b[j]]=1;
        for (int j=1; j<=n; j++)
        {
            u1[j]=0;
            u2[j]=0;
        }
        for (int p=i; p>=0; p--)
        {
            int f=s[p];
            int h=k1[p][s[p]];
            if (use[f][h]&&u1[f]==0) {res++; use[f][h]=0; u1[f]=1;}
        }
        for (int p=i+1; p<=n; p++)
        {
            int f=s[p];
            int h=k2[p][s[p]];
            if (use[f][h]&&u2[f]==0) {res++; use[f][h]=0; u2[f]=1;}
        }
        ans=max(ans,res);
    }
    for (int j=1; j<=m; j++)
        use[a[j]][b[j]]=1;
    for (int i=0; i<=n; i++)
    {
        int res=0;
        if (i!=0&&use[s[i]][k1[i][s[i]]]==0) continue;
        ll k=1;
        for (int j=1; j<=n; j++)
        {
            if (j==s[i])
            {
                int l=k1[i][s[i]];
                res++;
                int c1=0;
                for (int p=0; p<v[j].size(); p++)
                {
                    int r=v[j][p];
                    if (l!=r&&r<=k2[i+1][j]) c1++;
                }
                if (c1!=0)
                {
                    res++;
                    k=(k*1ll*c1);
                    if (k>1000000000) k%=MOD;
                }
            } else
            {
                int c1=0,c2=0;
                ll kol=0;
                for (int p=0; p<v[j].size(); p++)
                {
                    int r=v[j][p];
                    if (r<=k2[i+1][j]) c2++;
                    if (r<=k1[i][j]) c1++;
                }
                if (c1==1&&c2==1)
                {
                    res++;
                    kol+=2;
                } else
                if (c1>0&&c2>0)
                {
                    res+=2;
                    for (int p=0; p<v[j].size(); p++)
                    {
                        int r=v[j][p];
                        if (r<=k1[i][j]&&r<=k2[i+1][j])
                            kol+=c2-1; else
                        if (r<=k1[i][j]) kol+=c2;
                    }
                } else
                if (c1>0)
                {
                    res++;
                    kol=c1;
                } else
                if (c2>0)
                {
                    res++;
                    kol=c2;
                } else kol=1;
                k=(k*1ll*kol);
                if (k>1000000000ll) k%=MOD;
            }
        }
        ///cout<<"after "<<i<<" ans is "<<res<<endl;
        if (res==ans) { ///cout<<"after "<<i<<": "<<k<<endl;
        ans2=(ans2+1ll*k)%MOD;}
    }
    cout<<ans<<" "<<ans2<<endl;
}