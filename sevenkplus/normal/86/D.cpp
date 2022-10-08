#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 222222
#define P 1111111
struct T{int l,r,d;T(int L=0,int R=0,int D=0):l(L),r(R),d(D){}};
inline bool cmp(const T&a,const T&b){return a.l<b.l||a.l==b.l&&a.r<b.r;}
int a[N],p[P],n,m,l,r;ll S[N],s;vector<T> b[N/2200];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    for(int i=0,x,y;i<m;i++)scanf("%d%d",&x,&y),b[(y-x)/2200].push_back(T(x-1,y,i));
    for(int i=0;i<=n/2200;i++)if(b[i].size())
    {
        sort(b[i].begin(),b[i].end(),cmp);
        for(int j=0;j<b[i].size();j++)
        {
            T t=b[i][j];
            while(l>t.l)l--,s+=(ll)(p[a[l]]*2+1)*a[l],p[a[l]]++;
            while(l<t.l)p[a[l]]--,s-=(ll)(p[a[l]]*2+1)*a[l],l++;
            while(r<t.r)s+=(ll)(p[a[r]]*2+1)*a[r],p[a[r]]++,r++;
            while(r>t.r)r--,p[a[r]]--,s-=(ll)(p[a[r]]*2+1)*a[r];
            S[t.d]=s;
        }
    }
    for(int i=0;i<m;i++)printf("%I64d\n",S[i]);
    return 0;
}