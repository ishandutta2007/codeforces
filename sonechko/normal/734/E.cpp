#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 200000+10;
const int M = 10;
const string st2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define filestxt freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
#define y1 dbfuebfwkjNBSciwbe
#define time zdfheajbrkjasghduw
#define ull unsigned long long
#define randomize srand(time(NULL))
#define next ifhiuebf
#define last dkbffjrb
#define pb push_back
int color[N],use[N],pref[N],kil,pool[N],pres;
pair<int,int> q[N];
vector<int> v1[N],v[N];
void dfs(int l)
{
    use[l]=1;
    pref[l]=kil;
    for (int i=0; i<v1[l].size(); i++)
    {
        int to=v1[l][i];
        if (use[to]==1&&color[to]!=color[l])
        {
            v[kil].pb(pref[to]);
            v[pref[to]].pb(kil);
        }
        if (use[to]==0&&color[to]==color[l])
        {
            dfs(to);
        }
    }
}
void dfs2(int l, int r)
{
    pool[l]=0;
    use[l]=1;
    for (int i=0; i<v[l].size(); i++)
    {
        int to=v[l][i];
        if (use[to]==0) {dfs2(to,r+1);pool[l]=max(pool[l],pool[to]);}
    }
    pool[l]++;
}
int main()
{
    #ifdef LOCAL
    filestxt;
    #else
    sync;
    #endif // LOCAL
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>color[i];
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v1[l].pb(r);
        v1[r].pb(l);
    }
    for (int i=1; i<=n; i++)
        if (use[i]==0)
    {
        kil++;
        dfs(i);
    }
    n=kil;
    for (int i=1; i<=n; i++)
        use[i]=0;
    dfs2(1,1);
    for (int i=1; i<=n; i++)
        use[i]=0;
    int ans=INT_MAX;
    use[1]=1;
    int k1=1,k2=1;
    q[k1]=mp(1,0);
    pool[1]=0;
    while (k1<=k2)
    {
        int l=q[k1].f,r=q[k1].s;
        pool[l]++;
        k1++;
        int res=pool[l]-1,perf=0;
        int l1=0,r1=0,l2=0;
        l1=pool[l]-1;
        r1=l;
        for (int i=0; i<v[l].size(); i++)
        {
                int ft=pool[v[l][i]];
                res=max(res,ft);
                if (ft>l1)
                {
                    l2=l1;
                    l1=ft;
                    r1=v[l][i];
                } else
                if (ft>l2)
                {
                    l2=ft;
                }
        }
        for (int i=0; i<v[l].size(); i++)
        {
            if (use[v[l][i]]==0)
            {
                use[v[l][i]]=1;
                k2++;
                if (v[l][i]==r1) q[k2]=mp(v[l][i],l2+1);
                 else q[k2]=mp(v[l][i],l1+1);
                pool[v[l][i]]=q[k2].s;
            }
        }
        ans=min(ans,res);
    }
    cout<<ans<<endl;
}