#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define pb push_back
int x,y,n,m;vector<int> a;double S=1e20;
double dis(int a){return sqrt((ll)(a-x)*(a-x)+(ll)y*y);}
double fu(int l,int r){return min(abs(m-a[l])+dis(a[r]),abs(a[r]-m)+dis(a[l]))+a[r]-a[l];}
double fd(int l,int r){return min(dis(a[l]),dis(a[r]))+a[r]-a[l];}
int main()
{
    scanf("%d%d",&n,&m),--m;
    for(int i=0,x;i<n;i++)scanf("%d",&x),a.pb(x);
    scanf("%d%d",&x,&y);
    if(m==n)
    {
        sort(a.begin(),a.end());
        printf("%.9lf\n",fd(0,n-1));
        return 0;
    }
    m=a[m],sort(a.begin(),a.end());
    S=fu(0,n-1);
    for(int i=0;i<n;i++)
    {
        if(i!=0)S=min(S,fu(0,i-1)+fd(i,n-1));
        if(i!=n-1)S=min(S,fu(i+1,n-1)+fd(0,i));
    }
    printf("%.9lf\n",S);
    return 0;
}