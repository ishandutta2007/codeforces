#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define ss second

const ll N = 5e5 + 11;
const ll mod = 1e9 + 7;

int kol[N],dd,b[N];
ll res[N];
int tt,n;
int a[N],tin[N],tout[N],X[N],L[N],R[N];
int vv[N];
vector<int> v[N];

void update(int x, int t)
{
    for (int i=x; i<=100000; i=(i|(i+1)))
        vv[i]+=t;
}
int get(int r)
{
    int ans=0;
    for (int i=r; i>=0; i=(i&(i+1))-1)
        ans+=vv[i];
    return ans;
}

int get(int tl, int tr)
{
    return get(tr)-get(tl-1);
}

void mur(int l, int r)
{
    if (kol[a[l]]>=0) update(kol[a[l]],-1);
    kol[a[l]]+=r;
    if (kol[a[l]]>=0) update(kol[a[l]],1);
}

void dfs(int l, int pr)
{
    tt++;
    a[tt]=b[l];
    tin[l]=tt;
    for (int i=0; i<v[l].size(); i++)
    if (v[l][i]!=pr) dfs(v[l][i],l);
    tout[l]=tt;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>n>>t;
    for (int i=1; i<=n; i++)
        cin>>b[i];
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    dfs(1,0);
    vector<pair<int,pair<int,int> > > v;
    for (int i=1; i<=t; i++)
    {
        int l,r;
        cin>>l>>r;
        v.pb(mp(tin[l]/(int)sqrt(n),mp(tout[l],i)));
        X[i]=r;
        L[i]=tin[l];
        R[i]=tout[l];
    }
    sort(v.begin(),v.end());
    int l1=1,r1=1;
    mur(1,1);
    for (int i=0; i<v.size(); i++)
    {
        int num=v[i].ss.ss;
        int l=L[num];
        int r=R[num];
        int x=X[num];
        if (l<l1)
        {for (int i=l; i<l1; i++)
            mur(i,1);}
        if (l1<l)
        {for (int i=l1; i<l; i++)
            mur(i,-1);}
        l1=l;
        if (r>r1)
        {for (int i=r; i>r1; i--)
            mur(i,1);}
        if (r1>r)
        {for (int i=r1; i>r; i--)
            mur(i,-1);}
        r1=r;
        res[num]=get(x,100000);
    }
    for (int i=1; i<=t; i++)
        cout<<res[i]<<"\n";
}
/**

10 70
82 48 59 48 32 83 34 46 47 79
2 1
3 1
4 3
5 4
6 1
7 2
8 3
9 2
10 2

5 77
5 83
4 64
10 17
4 66
10 67
7 12
6 52
5 14
8 49
7 7
2 77
1 29
1 41
6 100
1 39
9 98
6 20
9 17
10 100
6 78
4 58
9 90
6 2
4 89
7 97
1 76
7 17
4 72
3 28
1 42
4 63
10 51
1 84
1 55
5 57
4 83
8 60
7 13
9 92
10 8
5 68
8 86
10 72
9 63
3 49
4 1
2 13
4 60
9 54
8 77
5 38
2 41
5 5
3 32
7 72
4 60
3 57
5 61
2 98
4 43
4 93
2 33
1 26
4 70
3 23
9 64
6 56
7 31
10 81

**/