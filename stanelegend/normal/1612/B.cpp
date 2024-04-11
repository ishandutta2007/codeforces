#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define LL long long
#define pii pair <int,int>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair

using namespace std;

int t,n,a,b;
bool vis[110];
vector <int> v,vv;

int main()
{
  ios::sync_with_stdio(false);
  cin>>t;
  rep(tn,t)
  {
    cin>>n>>a>>b;
    rep(i,n+3) vis[i]=false;
    v.clear();vv.clear();
    v.pb(a);vv.pb(b);vis[a]=vis[b]=true;
    int cc=n/2-1;
    for(int i=n;cc>0;--i) if(!vis[i])
    {
      vis[i]=true;
      v.pb(i);--cc;
    }
    if(v.back()<a)
    {
      cout<<-1<<endl;
      continue;
    }
    cc=n/2-1;
    for(int i=1;cc>0;++i) if(!vis[i])
    {
      vis[i]=true;
      vv.pb(i);--cc;
    }
    if(vv.back()>b)
    {
      cout<<-1<<endl;
      continue;
    }
    rep(i,v.size()) cout<<v[i]<<' ';rep(i,vv.size()) cout<<vv[i]<<' ';cout<<endl;
  }
  return 0;
}