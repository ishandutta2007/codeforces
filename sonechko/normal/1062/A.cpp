#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 11;

int a[N];

int up(int l, int r)
{
      if (l==r) return 0;
      if (l==1) return r-l;
      if (r==1000) return r-l;
      return r-l-1;
}

int main()
{
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      int n;
      cin>>n;
      int ans=0;
      for (int i=1; i<=n; i++)
      cin>>a[i];
      int pos=1;
      for (int i=1; i<=n; i++)
      if (a[i]!=a[i+1]-1) {ans=max(ans,up(a[pos],a[i])); pos=i+1;}
      cout<<ans<<endl;
}