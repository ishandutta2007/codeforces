#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

ll res[N];

vector<int> vv[N],v[N];
int gl[N];
ll sz[N];
int a[N];

int pr(int l)
{
    if (l==gl[l]) return l;
    return gl[l]=pr(gl[l]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        a[i]=l;
        for (int d=1; d<=(int)sqrt(l); d++)
            if (l%d==0)
        {
            v[d].pb(i);
            if (l/d!=d) v[l/d].pb(i);
        }
    }
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        vv[l].pb(r);
        vv[r].pb(l);
    }
    for (int i=200000; i>=1; i--)
    {
        for (int j=0; j<v[i].size(); j++)
        {
            int to=v[i][j];
            gl[to]=to;
            sz[to]=1;
            for (int p=0; p<vv[to].size(); p++)
            {
                int x=vv[to][p];
                if (a[x]%i==0&&gl[x]!=0)
                {
                    int p=pr(x);
                    if (p==to) continue;
                    gl[p]=to;
                    sz[to]+=sz[p];
                }
            }
        }
        for (int j=0; j<v[i].size(); j++)
        {
            int p=v[i][j];
            if (gl[p]==p) res[i]+=sz[p]*1ll*(sz[p]+1ll)/2ll;
        }
        for (int j=0; j<v[i].size(); j++)
        {
            sz[v[i][j]]=0;
            gl[v[i][j]]=0;
        }
        for (int j=i*2; j<=200000; j+=i)
            res[i]-=res[j];
    }
    for (int i=1; i<=200000; i++)
        if (res[i]>0) cout<<i<<" "<<res[i]<<"\n";
}