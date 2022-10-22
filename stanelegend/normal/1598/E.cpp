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

int n,m,q,lst[1010][1010],ans=0,lck_cnt,l;
bool lck[1010][1010];

bool out(int x,int y){return x<0||x>=n||y<0||y>=m;}

void initl(int x,int y)
{
  if(out(x,y)||out(x,y+1)) return;
  int mns=(int)(x==n-1),cnt=1;
  while(!out(x,y)&& !out(x,y+1))
  {
    lst[x][y]=(cnt+cnt-mns)*(x==0 ? 1:2);
    ans+=lst[x][y];
    --x;--y;++cnt;
  }
}

int getFir(int x,int y)
{
  while(!out(x,y))
  {
    if(lck[x][y]) return x;
    ++x;++y;
  }
  return x;
}

void calc(int x,int y,int xx,int yy)
{
  if(out(x,y)) return;
  if(lck[x][y]) xx=x;if(lck[x][y+1]) yy=x;
  int mul=(!out(x-1,y)&& !lck[x-1][y] ? 2:1);
  ans-=lst[x][y];//cout<<lst[x][y]<<"mins\n";
  int good=min(xx,yy)-x;
  if(good==0) lst[x][y]=0;
  else
  {
    int mns=(int)(out(x+good,y+good)||lck[x+good][y+good]);
    lst[x][y]=mul*(good+good-mns);
  }
  ans+=lst[x][y];//cout<<lst[x][y]<<"fjaksd\n";
  calc(x-1,y-1,xx,yy);
}

int main()
{
  cin>>n>>m>>q;
  rep(i,m-1) initl(n-1,i);
  rep(i,n-1) initl(i,m-2);
  l=m*(n-1);
  int x,y;
  rep(qn,q)
  {
    scanf("%d%d",&x,&y);--x;--y;
    if(lck[x][y])
    {
      --lck_cnt,lck[x][y]=false;
      if(!out(x-1,y)&& !lck[x-1][y]) ++l;
      if(!out(x+1,y)&& !lck[x+1][y]) ++l;
      if(!out(x+1,y+1))
      {
        ans+=lst[x+1][y];
        lst[x+1][y]+=lst[x+1][y];
      }
    }
    else
    {
      ++lck_cnt,lck[x][y]=true;
      if(!out(x-1,y)&& !lck[x-1][y]) --l;
      if(!out(x+1,y)&& !lck[x+1][y]) --l;
      if(!out(x+1,y+1))
      {
        ans-=lst[x+1][y]/2;
        lst[x+1][y]/=2;
      }
    }
    LL bas=n*m-lck_cnt+l;
    if(!out(x,y-1))
    {
      int xx=getFir(x,y-1),yy=getFir(x,y);
      calc(x,y-1,xx,yy);
    }
    if(!out(x,y+1))
    {
      int xx=getFir(x,y),yy=getFir(x,y+1);
      calc(x,y,xx,yy);
    }
    else if(!out(x-1,y-1))
    {
      int xx=getFir(x-1,y-1),yy=getFir(x-1,y);
      calc(x-1,y-1,xx,yy);
    }
    printf("%lld\n",ans+bas);/*
    cout<<ans<<' '<<l<<' '<<n*m-lck_cnt<<endl;
    rep(i,n)
    {
      rep(j,m) cout<<lst[i][j]<<'\t';
      cout<<endl;
    }*/
  }
  return 0;
}