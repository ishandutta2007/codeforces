#include<cstdio>
#include<vector>
#define N 100005
using namespace std;
int n,i,j,x,y,k,p,e,h,t,d[N],flag[N],s[N],q[N];
vector<int>a[N];
inline void add(int x,int y){a[x].push_back(y);}
int main()
{
  scanf("%d",&n);
  for (i=0;i<n;i++)
    scanf("%d%d",&d[i],&s[i]);
  for (i=0;i<n;i++) if (d[i]==1) q[++t]=i;h=0;
  while (h<t)
  {
    k=q[++h];if (flag[k]) continue;flag[k]=1;if(d[k]!=1)continue;
    p=s[k];if (!d[p]||flag[p]) continue;
    d[p]--;s[p]^=k;add(p,k);e++;
    if (d[p]==1) q[++t]=p;
  }
  printf("%d\n",e);
  for (i=0;i<n;i++)
    for (j=0;j<a[i].size();j++)
      printf("%d %d\n",i,a[i][j]);
}