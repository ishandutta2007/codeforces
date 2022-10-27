#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
typedef __int64 ll;
struct point{
    ll x,y;
}a,b,t,p[100000+2];
int n;double maxn=-10000000000,sum,res,da[100000+2],db[100000+2],f[100000+2],f1[100000+2];
double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    cin>>a.x>>a.y>>b.x>>b.y>>t.x>>t.y>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y;
        da[i]=dis(p[i],t)-dis(p[i],a),db[i]=dis(p[i],t)-dis(p[i],b);
        sum+=2*dis(p[i],t);
    }
    for(int i=1;i<=n;i++) f[i]=max(f[i-1],da[i]),f1[n-i+1]=max(f1[n-i+2],da[n-i+1]),maxn=max(maxn,da[i]);
    res=sum-maxn;
    for(int i=1;i<=n;i++) res = min(res,sum-db[i]-max(f1[i+1],f[i-1]));
    printf("%.6lf\n",res);
    return 0;
}