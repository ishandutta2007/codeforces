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

const LL MOD=1e9+7;

int t,n;
string s,ss;

int main()
{
  cin>>t;
  rep(tn,t)
  {
    cin>>n>>s>>ss;
    bool ok=true;
    rep(i,n) if(s[i]=='1'&&ss[i]=='1') ok=false;
    puts(ok ? "YES":"NO");
  }
  return 0;
}