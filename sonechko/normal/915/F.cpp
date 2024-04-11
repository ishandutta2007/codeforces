#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define ld long double

const int N = 1e6 + 11;

int sz[N],pr[N],a[N];

long long ans;

int gl(int l)
{
          if (l==pr[l]) return l;
          return pr[l]=gl(pr[l]);
}

void up(int l, int r, int k)
{
          int x=gl(l);
          int y=gl(r);
          if (x!=y)
          {
                    ans+=sz[x]*1ll*sz[y]*1ll*k;
                    sz[x]+=sz[y];
                    pr[y]=x;
          }
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    cin>>a[i];
    vector<pair<int,pair<int,int> > > v1,v2;
    for (int i=1; i<=n; i++)
    {
              int l,r;
              cin>>l>>r;
              v1.pb(mp(min(a[l],a[r]),mp(l,r)));
              v2.pb(mp(max(a[l],a[r]),mp(l,r)));
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for (int i=1; i<=n; i++)
    {
              pr[i]=i;
              sz[i]=1;
    }
    for (int i=v1.size()-1; i>=0; i--)
    {
              int k=v1[i].ff,l=v1[i].ss.ff,r=v1[i].ss.ss;
              up(l,r,-k);
    }
    for (int i=1; i<=n; i++)
    {
              pr[i]=i;
              sz[i]=1;
    }
    for (int i=0; i<v2.size(); i++)
    {
              int k=v2[i].ff,l=v2[i].ss.ff,r=v2[i].ss.ss;
              up(l,r,k);
    }
    cout<<ans<<endl;
}