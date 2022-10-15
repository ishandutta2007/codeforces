#include<cmath>
#include<set>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 1000020

using namespace std;
typedef long long ll;

struct point{
    int x,y;
};

bool cmp(point u,point v)
{
    return u.x<v.x;
}

int n,a[maxn],k,t,cnt,ans,sum[maxn],s;
point p[maxn];

void add_p(int z,int w)
{
    p[k].x=z;
    p[k].y=w;
    k++;
}

int main()
{
    scanf("%d%d",&n,&t);k=0;
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]=max(a[i],i);
    }
    for (int i=1;i<=n;i++)
    if (t>a[i]){
        add_p(a[i]-i,1);
        if (t>=a[i]) add_p(t-i,-1);
    }
    sort(p,p+k,cmp);ans=0;s=0;
    //for (int i=0;i<k;i++)
        //printf("%d %d\n",p[i].x,p[i].y);
    for (int i=0;i<k;i++){
        sum[++cnt]=p[i].y;
        while (i+1<k&&p[i+1].x==p[i].x){
            i++;
            sum[cnt]+=p[i].y;
        }
        s+=sum[cnt];
        ans=max(ans,s);
    }
    printf("%d\n",ans);
}