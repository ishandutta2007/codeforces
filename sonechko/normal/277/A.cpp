#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
#define y1 kdnfskefn
#define sqr(a) ((a)*(a))
const int N = 2e2 + 11;
///-----------------------------------------------------------
int a[N][N],used[N],ans,glava[N],n;
vector<pair<int,pair<int,int> > > v;
///-----------------------------------------------------------
int gl(int l)
{
    if (glava[l]==l) return l;
    glava[l]=gl(glava[l]);
    return glava[l];
}
///-----------------------------------------------------------
void snm(int k, int l, int r)
{
    int x=gl(l);
    int y=gl(r);
    if (x==y) return;
    ans+=k;
    glava[x]=y;
}
///-----------------------------------------------------------
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        a[i][j]=1;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        for (int j=1; j<=l; j++)
        {
            int p;
            cin>>p;
            used[p]=1;
            a[i][p]=0;
        }
    }
    int k=0;
    for (int j=1; j<=m; j++)
        if (used[j]==1) k++;
    if (k==0) used[1]=1;
    for (int i=1; i<=n+m; i++)
        glava[i]=i;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        if (used[j]==1) v.pb(mp(a[i][j],mp(i,n+j)));
    sort(v.begin(),v.end());
    for (int i=0; i<v.size(); i++)
        snm(v[i].ff,v[i].ss.ff,v[i].ss.ss);
    cout<<ans<<endl;
}