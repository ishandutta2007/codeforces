#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define F(i) for(b[i]=2;b[i]--;swap(a[i][0],a[i][2]),swap(a[i][1],a[i][3]),x[i][0]=-x[i][0],x[i][1]=-x[i][1])
typedef long long ll;
typedef long double ld;
ld d(ll a,ll b,ll c,ll d){return sqrt((c-a)*(c-a)+(d-b)*(d-b));}
int main()
{
    int t,b[3],a[3][4];
    ll x[3][2];
    bool f,g;
    for(scanf("%d",&t);f=g=0,t--;)
    {
        for(int i=0;i<3;f|=(a[i][0]==a[i][2]&&a[i][1]==a[i][3]),x[i][0]=a[i][2]-a[i][0],x[i][1]=a[i][3]-a[i][1],i++)
            for(int j=0;j<4;scanf("%d",&a[i][j]),j++);
        F(0)F(1)F(2)
        for(int i=0;i<3;i++)
            for(int j=i+1;j<3;j++)
            {
                if(a[i][0]!=a[j][0]||a[i][1]!=a[j][1]||f||g||x[i][0]*x[j][0]+x[i][1]*x[j][1]<0||x[i][0]*x[j][1]==x[i][1]*x[j][0])continue;
                int k=3-i-j;
                ld a0=d(a[i][0],a[i][1],a[k][0],a[k][1]),a1=d(a[k][0],a[k][1],a[i][2],a[i][3]),b0=d(a[j][0],a[j][1],a[k][2],a[k][3]),b1=d(a[k][2],a[k][3],a[j][2],a[j][3]);
                if(fabs(a0+a1-d(a[i][0],a[i][1],a[i][2],a[i][3]))>1e-10||fabs(b0+b1-d(a[j][0],a[j][1],a[j][2],a[j][3]))>1e-10)continue;
                if(a0>a1)swap(a0,a1);
                if(b0>b1)swap(b0,b1);
                g|=(a0*4>=a1)&&(b0*4>=b1);
            }
        puts(f||!g?"NO":"YES");
    }
    return 0;
}