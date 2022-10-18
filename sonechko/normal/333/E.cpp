#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double

const int N = 3000 + 11;
const int MOD = 1e9 + 7;

int a[N],b[N];
bitset<N> c[N];
int n;

int dist(int l, int r)
{
    return (a[l]-a[r])*(a[l]-a[r])+(b[l]-b[r])*(b[l]-b[r]);
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.precision(8);
    cout<<fixed;

    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i]>>b[i];
    vector<pair<int,pair<int,int> > > vv;
    for (int i=1; i<=n; i++)
    for (int j=i+1; j<=n; j++)
        vv.pb(mp(dist(i,j),mp(i,j)));
    sort(vv.begin(),vv.end());
    for (int j=vv.size()-1; j>=0; j--)
    {
        int l=vv[j].ss.ff,r=vv[j].ss.ss;
        if ((c[l]&c[r]).count()>0) {cout<<(ld)sqrt((ld)vv[j].ff)/(ld)2; exit(0);}
        c[l][r]=1;
        c[r][l]=1;
    }
    cout<<0;
}