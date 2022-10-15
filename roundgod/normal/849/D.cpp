#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,w,h;
struct dc
{
    int lab,pos,num,edx,edy;
}a[MAXN];
bool cmp(dc x,dc y)
{
    if(x.pos!=y.pos) return x.pos<y.pos;
    if(x.lab!=y.lab) return x.lab<y.lab;
    if(x.lab==1) return x.edx<y.edx;
    if(x.lab==2) return x.edy>y.edy;
}
pair<int,int> ans[MAXN];
int main()
{
    scanf("%d %d %d",&n,&w,&h);
    for(int i=0;i<n;i++)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        a[i].lab=x;
        a[i].pos=y-z;
        a[i].num=i+1;
        if(a[i].lab==1) {a[i].edx=y;a[i].edy=h;}
        if(a[i].lab==2) {a[i].edx=w;a[i].edy=y;}
    }
    sort(a,a+n,cmp);
    int k=0;
    while(k<n)
    {
        int cnt1=0,cnt2=0;
        int x=a[k].pos,t=k;
        while(a[k].pos==x&&k<n)
        {
            if(a[k].lab==1) cnt1++; else cnt2++;
            k++;
        }
        int p=t+cnt1,q=t;
        for(int i=t;i<k;i++)
        {

            if(p<k)
            {
                ans[a[p].num].first=a[i].edx;
                ans[a[p].num].second=a[i].edy;
                p++;
            }
            else
            {
                ans[a[q].num].first=a[i].edx;
                ans[a[q].num].second=a[i].edy;
                q++;
            }
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}