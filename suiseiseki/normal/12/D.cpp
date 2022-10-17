#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct data
{
 int a,b,c,id;
}p[500003],res[500003];
int n,t,tot,c[500003],ds[500003],f[500003],ans;
inline int read()
{
  register int cnt=0,f=1,ch=getchar();
  while (ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
  while (ch>='0'&&ch<='9'){cnt=cnt*10+ch-48;ch=getchar();}
  return cnt*f;
}
inline int find(int x)
{
  int l=1,r=tot,mid;
  while (l<=r)
  {
    mid=(l+r)>>1;
    if (ds[mid]==x) return mid;
    if (ds[mid]>x) r=mid-1;
    if (ds[mid]<x) l=mid+1;
  }
}
inline void clear(int x)
{
  for (int i=x;i<=500000;i+=i&-i)
   c[i]=0;
}
inline void add(int x)
{ 
  for (int i=x;i<=500000;i+=i&-i)
   c[i]++;
}
inline int query(int x)
{
  int res=0;
  for (int i=x;i;i-=i&-i)
   res+=c[i];
  return res;
}
inline bool cmp(data x,data y)
{
  return x.a>y.a||(x.a==y.a&&x.c<y.c);
}
void solve(int l,int r)
{
  int mid=(l+r)>>1,x=l,y=mid+1,len=0;
  while (x<=mid&&y<=r)
  {
    if (p[x].b>p[y].b){add(p[x].c);res[++len]=p[x++];}
    else {f[p[y].id]+=x-l-query(p[y].c);res[++len]=p[y++];}
  }
  while (x<=mid) res[++len]=p[x++];
  while (y<=r) {f[p[y].id]+=x-l-query(p[y].c);res[++len]=p[y++];}
  for (int i=l;i<=mid;i++)
   clear(p[i].c);
  for (int i=1;i<=len;i++) 
   p[l+i-1]=res[i];
}
inline void CDQ(int l,int r)
{
  int mid=(l+r)>>1;
  if (l==r) return;
  CDQ(l,mid);
  CDQ(mid+1,r);
  solve(l,r);
}
int main()
{
  n=read();
  for (int i=1;i<=n;i++)
   {p[i].id=i;p[i].a=read();}
  for (int i=1;i<=n;i++)
   p[i].b=read();
  for (int i=1;i<=n;i++)
   ds[i]=p[i].c=read();

  sort(ds+1,ds+1+n);
  tot=1;
  t=ds[1];
  for (int i=2;i<=n;i++)
   if (ds[i]!=t){ds[++tot]=ds[i];t=ds[i];}
  for (int i=1;i<=n;i++)
   p[i].c=find(p[i].c);

  sort(p+1,p+1+n,cmp);

  CDQ(1,n);

  for (int i=1;i<=n;i++)
   if (f[i]>0) ans++;
  printf("%d\n",ans);
  return 0;
}