#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

int t,hv[30];
string s;

int main()
{
  ios::sync_with_stdio(false);
  cin>>t;
  rep(tn,t)
  {
    cin>>s;
    rep(i,28) hv[i]=0;
    int mn=1e9;
    for(int i=s.size()-1;i>=0;--i)
    {
      if(hv[s[i]-'a']==0) mn=i;
      hv[s[i]-'a']=1;
    }
    cout<<s.substr(mn)<<endl;
  }
  return 0;
}