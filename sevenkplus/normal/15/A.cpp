#include<cstdio>
#include<algorithm>
struct ln{int x,y;}a[1000];
inline bool cmp(const ln&a,const ln&b){return a.x<b.x;}
int main()
{
    int n,l,x,y,s=2;
    scanf("%d%d",&n,&l),l*=2;
    for(int i=0;i<n;scanf("%d%d",&x,&y),a[i].x=x*2-y,a[i].y=x*2+y,i++);
    std::sort(a,a+n,cmp);
    for(int i=1;i<n;s+=(a[i].x-a[i-1].y>=l)+(a[i].x-a[i-1].y>l),i++);
    printf("%d\n",s);
    return 0;
}