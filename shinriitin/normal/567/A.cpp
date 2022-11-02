#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 100005
using namespace std;

struct city{
    int x,id;
    inline bool operator<(const city&o)const{
        return x<o.x;
    }
}a[MAXN];

int n,ans1[MAXN],ans2[MAXN];

inline int Abs(int x){
    return x>0?x:-x;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i].x);
        a[i].id=i;
    }
    sort(a+1,a+1+n);
    int mx1=a[1].x,mx2=a[n].x;
    for(int i=1;i<=n;++i){
        ans1[i]=0x7fffffff;
        ans2[a[i].id]=max(a[a[i].id].x-mx1,mx2-a[a[i].id].x);
    }
    for(int i=2;i<=n;++i){
        ans1[a[i-1].id]=min(ans1[a[i-1].id],Abs(a[i].x-a[i-1].x));
        ans1[a[i].id]=min(ans1[a[i].id],Abs(a[i].x-a[i-1].x));
    }
    for(int i=1;i<=n;++i){
        printf("%d %d\n",ans1[i],ans2[i]);
    }
    return 0;
}