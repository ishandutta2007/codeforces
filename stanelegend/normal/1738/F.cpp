#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back

using namespace std;

int t,n,d[1010],fa[1010],c[10010];
bool con[1010];
set <pii> st;

int qry(int u)
{
  cout<<"? "<<u<<endl;
  cout.flush();
  int x;cin>>x;return x;
}

int Find(int x)
{
  if(fa[x]!=x) fa[x]=Find(fa[x]);
  return fa[x];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  cin>>t;
  rep(tn,t)
  {
    cin>>n;
    repn(i,n) cin>>d[i];
    repn(i,n) fa[i]=i,con[i]=0;
    st.clear();
    repn(i,n) st.insert(mpr(-d[i],i));
    LL cnt=0;
    while(cnt<n)
    {
      pii bg=*st.begin();st.erase(st.begin());
      bg.fi=-bg.fi;
      con[bg.se]=true;
      ++cnt;
      rep(i,bg.fi)
      {
        int v=qry(bg.se);
        if(con[v])
        {
          fa[Find(bg.se)]=Find(v);
          break;
        }
        con[v]=true;fa[Find(v)]=Find(bg.se);
        st.erase(mpr(-d[v],v));
        ++cnt;
      }
    }
    cout<<"! ";
    int len=0;
    repn(i,n) if(Find(i)==i) c[i]=++len;
    repn(i,n) if(Find(i)!=i) c[i]=c[Find(i)];
    repn(i,n) cout<<c[i]<<' ';cout<<endl;
    cout.flush();
  }
	return 0;
}