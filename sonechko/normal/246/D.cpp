#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define ull unsigned long long

const int N = 1e5 + 11;

int a[N];
vector<int> vv[N];
map<int,bool> mt;
vector<int> v[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        vv[a[i]].pb(i);
    }
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    int kk=-1,pp=0;
    for (int j=1; j<=100000; j++)
        if (vv[j].size()>0)
    {
        mt.clear();
        int rr=0;
        int jj=j;
        for (int d=0; d<vv[j].size(); d++)
        {
            int l=vv[j][d];
            for (int j=0; j<v[l].size(); j++)
                if (a[v[l][j]]!=jj&&mt[a[v[l][j]]]==0)
            {
                mt[a[v[l][j]]]=1;
                rr++;
            }
        }
        if (rr>kk) {kk=rr; pp=j;}
    }
    cout<<pp<<endl;
}