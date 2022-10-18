#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int T;cin>>T;
  while (T--)
  {
    int n,m,i,r=0;
    cin>>n>>m;
    vector<int> a(n),cnt(n);
    vector e(n,vector(0,0));
    for (int &x:a) cin>>x;
    for (i=0;i<m;i++)
    {
      int u,v;
      cin>>u>>v;
      ++cnt[u-1],++cnt[v-1];
      e[u-1].push_back(v-1);
    }
    if (m&1)
    {
      r=1e9;
      for (i=0;i<n;i++) if (cnt[i]&1) r=min(r,a[i]);
      for (i=0;i<n;i++) for (int v:e[i]) if (cnt[i]+cnt[v]+1&1) r=min(r,a[i]+a[v]);
    }
    cout<<r<<'\n';
  }
}