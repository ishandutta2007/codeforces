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

int t,n,k;
string s[50];

int main()
{
  cin>>t;
  rep(tn,t)
  {
    cin>>n>>k;
    int can=(n+1)/2;
    if(k>can)
    {
      puts("-1");
      continue;
    }
    rep(i,n)
    {
      s[i]="";
      rep(j,n) s[i].pb('.');
    }
    rep(i,k) s[i+i][i+i]='R';
    rep(i,n) cout<<s[i]<<endl;
  }
  return 0;
}