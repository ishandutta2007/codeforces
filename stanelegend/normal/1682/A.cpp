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

int t,n;
string s;

int main()
{
  cin>>t;
  rep(tn,t)
  {
    cin>>n>>s;
    int mns=0;
    if(n%2==0)
    {
      mns=1;
      string tt=s.substr(0,n/2);tt.pb(s[n/2]);tt+=s.substr(n/2);
      s=tt;
    }
    int cnt=1;
    for(int i=s.size()/2-1;i>=0;--i)
    {
      if(s[i]!=s[i+1]) break;
      cnt+=2;
    }
    cout<<cnt-mns<<endl;
  }
	return 0;
}