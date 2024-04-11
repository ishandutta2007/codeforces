#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define LL long long
#define pii pair <LL,LL>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair

using namespace std;

LL t,n,m,a[100010],fwd[100010],bk[100010],ori[100010],mp[100010];
vector <LL> b[100010];
vector <pair <pii,LL> > stu;//{{sum,sz},id}
string ans;

bool cmp(pair <pii,LL> x,pair <pii,LL> y){return x.fi.fi*y.fi.se<y.fi.fi*x.fi.se;}

LL check(LL stid,LL tid)
{
  if(tid<0||tid>=m) return 1;
  return (stu[stid].fi.fi<=a[tid]*stu[stid].fi.se ? 0:1);
}

LL check2(LL sum,LL sz,LL sid){return (sum<=a[sid]*sz ? 1:0);}

bool good(LL mid,LL sum,LL sz)
{
  if(mid==0) return true;
  --mid;
  return stu[mid].fi.fi*sz<sum*stu[mid].fi.se;
}

LL findPos(LL sum,LL sz)
{
  LL lb=0,ub=stu.size(),mid;
  while(lb<ub)
  {
    mid=(lb+ub+1)/2;
    if(good(mid,sum,sz)) lb=mid;
    else ub=mid-1;
  }
  return lb;
}

LL getInter(LL lb,LL ub,LL val)
{
  if(lb>ub) return 1;
  if(val==0) return (fwd[ub+1]-fwd[lb]>0 ? 0:1);
  if(val==1) return (ori[ub+1]-ori[lb]>0 ? 0:1);
  return (bk[ub+1]-bk[lb]>0 ? 0:1);
}

int main()
{
  cin>>t;
  rep(tn,t)
  {
    scanf("%lld%lld",&n,&m);
    rep(i,n) scanf("%lld",&a[i]);
    sort(a,a+n);reverse(a,a+n);reverse(a,a+m);
    stu.clear();
    rep(i,m)
    {
      b[i].clear();
      LL x,y,z=0;
      scanf("%lld",&x);
      rep(j,x)
      {
        scanf("%lld",&y);
        b[i].pb(y);z+=y;
      }
      stu.pb(mpr(mpr(z,x),i));
    }
    sort(stu.begin(),stu.end(),cmp);
    rep(i,m)
    {
      fwd[i+1]=check(i,i-1);
      ori[i+1]=check(i,i);
      bk[i+1]=check(i,i+1);
      mp[stu[i].se]=i;
    }
    rep(i,m)
    {
      fwd[i+1]+=fwd[i];
      ori[i+1]+=ori[i];
      bk[i+1]+=bk[i];
    }
    ans="";
    rep(i,m)
    {
      LL id=mp[i];
      rep(j,b[i].size())
      {
        LL sum=stu[id].fi.fi-b[i][j],sz=b[i].size()-1,p=findPos(sum,sz),lb1=0,ub1=id-1,lb2=id+1,ub2=m-1,ok=1;
        if(p==id||p==id+1) ok&=getInter(lb1,ub1,1)&getInter(lb2,ub2,1)&check2(sum,sz,id);
        else if(p<id) ok&=getInter(0,p-1,1)&check2(sum,sz,p)&getInter(p,id-1,2)&getInter(lb2,ub2,1);
        else ok&=getInter(lb1,ub1,1)&getInter(id+1,p-1,0)&check2(sum,sz,p-1)&getInter(p,m-1,1);
        ans.pb(ok==1 ? '1':'0');
      }
    }
    printf("%s\n",ans.c_str());
  }
  return 0;
}