#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000000000;
const int N = 100+10;
const int M = 100;
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
int use[N][N],a[N][N],plo=0,put=0,n,m;
pair<int,pair<int,int> > p[N*N];
bool good(int l, int r, int k)
{
    if (l>=1&&r>=1&&l<=n&&r<=m&&use[l][r]!=k
        &&a[l][r]==0) return true; else return false;
}
void dfs(int l, int r)
{
    if (l==1||r==1||l==n||r==m) put=1;
    plo++;
    use[l][r]=1;
    if (good(l+1,r,1)) dfs(l+1,r);
    if (good(l-1,r,1)) dfs(l-1,r);
    if (good(l,r-1,1)) dfs(l,r-1);
    if (good(l,r+1,1)) dfs(l,r+1);
}
void dfs1(int l, int r)
{
    use[l][r]=2;
    a[l][r]=1;
    if (good(l+1,r,2)) dfs1(l+1,r);
    if (good(l-1,r,2)) dfs1(l-1,r);
    if (good(l,r-1,2)) dfs1(l,r-1);
    if (good(l,r+1,2)) dfs1(l,r+1);
}
int main()
{
    int k;
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        char ch;
        cin>>ch;
        if (ch=='*') a[i][j]=1;
    }
    int kol=0;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    if (use[i][j]==0&&a[i][j]==0)
    {
        plo=0;
        put=0;
        dfs(i,j);
        if (put==0)
            {
                kol++;
                p[kol]=mp(plo,mp(i,j));
            }
    }
    sort(p+1,p+kol+1);
    int ans=0;
    for (int i=kol-k; i>=1; i--)
{
        ans+=p[i].f;
        dfs1(p[i].s.f,p[i].s.s);
    }
    cout<<ans<<endl;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
            if (a[i][j]==1) cout<<"*"; else
            cout<<".";
        cout<<endl;
    }

    cout<<endl;
}