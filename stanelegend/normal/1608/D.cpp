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

const LL MOD=998244353;

LL qpow(LL x,LL a)
{
	LL res=x,ret=1;
	while(a>0)
	{
		if((a&1)==1) ret=ret*res%MOD;
		a>>=1;
		res=res*res%MOD;
	}
	return ret;
}

namespace NTT
{
  vector <LL> rev;
  void ntt(vector <LL> &a,LL G)
  {
    LL nn=a.size(),gn,g,x,y;vector <LL> tmp=a;
    rep(i,nn) a[i]=tmp[rev[i]];
    for(int len=1;len<nn;len<<=1)
    {
      gn=qpow(G,(MOD-1)/(len<<1));
      for(int i=0;i<nn;i+=(len<<1))
      {
        g=1;
        for(int j=i;j<i+len;++j,(g*=gn)%=MOD)
        {
          x=a[j];y=a[j+len]*g%MOD;
          a[j]=(x+y)%MOD;a[j+len]=(x-y+MOD)%MOD;
        }
      }
    }
  }
  vector <LL> convolution(vector <LL> a,vector <LL> b,LL G)
  {
    LL nn=1,bt=0,sv=a.size()+b.size()-1;while(nn<a.size()+b.size()-1) nn<<=1LL,++bt;
    while(a.size()<nn) a.pb(0);while(b.size()<nn) b.pb(0);
    rev.clear();
    rep(i,nn)
    {
      rev.pb(0);
      rev[i]=(rev[i>>1]>>1)|((i&1)<<(bt-1));
    }
    ntt(a,G);ntt(b,G);
    rep(i,nn) (a[i]*=b[i])%=MOD;
    ntt(a,qpow(G,MOD-2));
    while(a.size()>sv) a.pop_back();
    LL inv=qpow(nn,MOD-2);
    rep(i,a.size()) (a[i]*=inv)%=MOD;
    return a;
  }
}

LL n,ww,bb,posi,nega,fac[100010],inv[100010];
string s[100010];
vector <LL> A,B,res;

LL C(LL nn,LL mm){return fac[nn]*inv[nn-mm]%MOD*inv[mm]%MOD;}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  fac[0]=1;repn(i,100005) fac[i]=fac[i-1]*(LL)i%MOD;
  rep(i,100003) inv[i]=qpow(fac[i],MOD-2);
  cin>>n;
  rep(i,n)
  {
    cin>>s[i];
    if(s[i]=="WW") ++ww;
    else if(s[i]=="BB") ++bb;
    else if(s[i]=="??") ++posi,++nega;
    else if(s[i]=="W?"||s[i]=="?W") ++posi;
    else if(s[i]=="B?"||s[i]=="?B") ++nega;
  }
  rep(i,posi+1) A.pb(C(posi,i));
  rep(i,nega+1) B.pb(C(nega,i));
  res=NTT::convolution(A,B,3);
  int need=bb-ww+nega;
  LL ans=(0<=need&&need<res.size() ? res[need]:0),sub=1;
  rep(i,n)
  {
    LL mul=0;
    if((s[i][0]=='W'||s[i][0]=='?')&&(s[i][1]=='B'||s[i][1]=='?')) ++mul;
    if((s[i][0]=='B'||s[i][0]=='?')&&(s[i][1]=='W'||s[i][1]=='?')) ++mul;
    (sub*=mul)%=MOD;
  }
  (ans+=MOD-sub)%=MOD;
  LL a1=1,a2=1;
  rep(i,n)
  {
    if(s[i][0]=='B'||s[i][1]=='W') a1=0;
    if(s[i][0]=='W'||s[i][1]=='B') a2=0;
  }
  (ans+=a1+a2)%=MOD;
  cout<<ans<<endl;
	return 0;
}