#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct T{int x,y,z;double p;void get(){scanf("%d%d%d%lf",&x,&y,&z,&p);}}a[1100];
bool cmp(const T&a,const T&b){return a.z<b.z;}
double dis(T a,T b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
int n;double f[1100],S;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)a[i].get();
    sort(a,a+n,cmp);
    S=f[0]=a[0].p;
    for(int i=1;i<n;i++)
    {
        f[i]=a[i].p;
        for(int j=0;j<i;j++)
            if(dis(a[i],a[j])<a[i].z-a[j].z+1e-8)f[i]=max(f[i],f[j]+a[i].p);
        S=max(S,f[i]);
    }
    printf("%.9lf\n",S);
    return 0;
}