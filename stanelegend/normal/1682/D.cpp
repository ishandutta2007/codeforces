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

int t,n,hv[200010];
string s;

void out(int st,int cur)
{
  cout<<st+1<<' '<<cur+1<<endl;
  hv[st]^=1;hv[cur]^=1;
}

int main()
{
  ios::sync_with_stdio(false);
  cin>>t;
  rep(tn,t)
  {
    cin>>n>>s;rep(i,n+3) hv[i]=0;
    int tot=0,cnt=0;
    rep(i,n) if(s[i]=='1') tot^=1,++cnt;
    if(tot!=0||cnt==0)
    {
      cout<<"NO\n";
      continue;
    }
    if(cnt==n)
    {
      cout<<"YES\n";
      repn(i,n-1) cout<<n<<' '<<i<<endl;
      continue;
    }
    int st=-1;rep(i,n) if(s[i]=='0'&&s[(i-1+n)%n]=='1') st=i;
    int cur=(st+1)%n,lst=st;
    cout<<"YES\n";
    while(true)
    {
      if(s[cur]=='1')
      {
        if(lst==st) out(cur,st);
        else
        {
          if(hv[lst]==1) out(lst,cur);
          else out(cur,st);
        }
        cur=(cur+1)%n;
        if(cur==st) break;
      }
      else
      {
        out(cur,st);
        lst=cur;
        while(true)
        {
          cur=(cur+1)%n;
          if(s[cur]=='1') break;
          out(cur,lst);lst=cur;
        }
      }
    }
  }
	return 0;
}