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

int n;
vector <int> v;

vector <int> comb(vector <int> aa,vector <int> bb)
{
  rep(i,bb.size()) aa.pb(bb[i]);
  return aa;
}

int ask(vector <int> aa)
{
  cout<<"? "<<aa.size()<<' ';
  rep(i,aa.size()) cout<<aa[i]<<' ';cout<<endl;cout.flush();
  string s;cin>>s;return s[0]=='Y' ? 1:0;
}

void guess(int x)
{
  cout<<"! "<<x<<endl;cout.flush();
  string s;cin>>s;
  if(s[1]==')') exit(0);
}

int main()
{
  ios::sync_with_stdio(false);
  cin>>n;
  repn(i,n) v.pb(i);
  while(v.size()>3)
  {
    int bas=v.size()/4,mo=bas+1,mocnt=v.size()%4;
    vector <int> vv[4];
    int cur=0;
    rep(i,4)
    {
      if(i<mocnt) rep(j,mo) vv[i].pb(v[cur++]);
      else rep(j,bas) vv[i].pb(v[cur++]);
    }
    int r1=ask(comb(vv[0],vv[1])),r2=ask(comb(vv[0],vv[2]));
    if(r1&&r2) v=comb(vv[0],comb(vv[1],vv[2]));
    else if(r1&& !r2) v=comb(vv[0],comb(vv[1],vv[3]));
    else if(!r1&&r2) v=comb(vv[0],comb(vv[2],vv[3]));
    else v=comb(vv[1],comb(vv[2],vv[3]));
  }
  if(v.size()==3)
  {
    int r1=ask({v[0]}),r2=ask({v[1]}),r3=ask({v[1]}),r4=ask({v[0]});
    if(r2==r3)
    {
      if(r2==1) guess(v[1]);
      else guess(v[0]),guess(v[2]);
    }
    else if(r1==r4)
    {
      if(r1==1) guess(v[0]);
      else guess(v[1]),guess(v[2]);
    }
    else guess(v[0]),guess(v[2]);
  }
  else rep(i,v.size()) guess(v[i]);
  return 0;
}