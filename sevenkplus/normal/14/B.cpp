#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n,x,l,r,L=-1,R=1001;
    for(scanf("%d%d",&n,&x);n--;scanf("%d%d",&l,&r),L=max(L,min(l,r)),R=min(R,max(l,r)));
    if(L>R)
        puts("-1");
    else
        if(x<L)
            printf("%d\n",L-x);
        else
            if(R<x)
                printf("%d\n",x-R);
            else
                puts("0");
    return 0;
}