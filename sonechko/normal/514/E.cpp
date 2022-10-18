#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 100 + 11;
const int MOD = 1e9 + 7;

int a[N][N],kol[N];

vector<vector<ll> > get(vector<vector<ll> > a, vector<vector<ll> > b)
{
    vector<vector<ll> > c;
    int n=a.size(),k=b[0].size();
    for (int i=0; i<n; i++)
    {
        vector<ll> d;
        for (int j=0; j<k; j++)
        {
            ll p=0;
            for (int d1=0; d1<a[i].size(); d1++)
                p=(p+a[i][d1]*b[d1][j])%MOD;
            d.pb(p);
        }
        c.pb(d);
    }
    return c;
}

void write(vector<vector<ll> > c)
{
    for (int j=0; j<c.size(); j++)
    {
        for (int k=0; k<c[j].size(); k++)
            cout<<c[j][k]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

vector<vector<ll> > step(vector<vector<ll> > a, ll st)
{
    if (st==1) return a;
    if (st%2==1)
    {
        vector<vector<ll> > p=step(a,st-1);
        return get(p,a);
    }
    vector<vector<ll> > p=step(a,st/2);
    return get(p,p);
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        kol[l]++;
    }
    for (int i=1; i<100; i++)
        a[i][i+1]=1;
    for (int i=1; i<=100; i++)
        a[i][1]=kol[i];
    a[1][0]=1;
    a[0][0]=1;
    vector<vector<ll> > vv;
    for (int i=0; i<=100; i++)
    {
        vector<ll> v;
        for (int j=0; j<=100; j++)
            v.pb(a[i][j]);
        vv.pb(v);
    }
    vector<vector<ll> > vvv=step(vv,m+1);
    cout<<vvv[1][0]<<endl;
}