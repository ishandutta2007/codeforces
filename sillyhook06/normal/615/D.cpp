#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 200005
#define M 200005
#define seed 23333
#define Mo 1000000007

using namespace std;
int i,j,m,n,p,k,x[N],ans=1,qian[N],hou[N];
int power(int x,int y)
{
   int sum=1;
   for (;y;y>>=1)
   {
     if (y&1) sum=1ll*sum*x%Mo;
     x=1ll*x*x%Mo;
   }
   return sum;
}
int main()
{   
      scanf("%d",&n);
      for (i=1;i<=n;++i) scanf("%d",&p),x[p]++;
      hou[N-1]=1; for (j=N-2;j>=1;--j) hou[j]=1ll*hou[j+1]*(x[j]+1)%(Mo-1);
      qian[1]=1;   for (j=2;j<N;++j) qian[j]=1ll*qian[j-1]*(x[j]+1)%(Mo-1);
      for (i=2;i<N;++i)
         if (x[i])
         {
                 int sm=1;
                 for (j=1;j<=x[i];++j) sm=1ll*sm*power(i,j)%Mo;
                 ans=1ll*ans*power(sm,1ll*qian[i-1]*hou[i+1]%(Mo-1))%Mo;
         }
      printf("%d\n",ans);
}