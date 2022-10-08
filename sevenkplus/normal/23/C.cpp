#include<cstdio>
#include<algorithm>
struct T{int x,y,z;}a[262145];
inline bool cmp(const T&a,const T&b){return a.x<b.x;}
int n;
int main()
{
    int _;scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);for(int i=1;i<n+n;i++)scanf("%d%d",&a[i].x,&a[i].y),a[i].z=i;
        std::sort(a+1,a+n+n,cmp),puts("YES");
        for(int i=2;i<n+n;i+=2)printf("%d ",a[a[i-1].y>a[i].y?i-1:i].z);printf("%d\n",a[n+n-1].z);
    }
    return 0;
}