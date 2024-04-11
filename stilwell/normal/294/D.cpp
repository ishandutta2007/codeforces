#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <set>
using namespace std;

int n,m,i,j,k,x,y,dx,dy,l1,l2,l;
long long ans;
char s[5];

set <pair<int,int> > Hash;

int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d%d",&x,&y);
    scanf("%s",s+1);
    if(s[1]=='U')dx=-1;else dx=1;
    if(s[2]=='L')dy=-1;else dy=1;
    for(i=n+n+m+m;i;--i)
    {
        Hash.insert(make_pair(x,y));
        if(Hash.size()==n+m-2)
        {
            printf("%I64d\n",ans+1);
            return 0;
        }
        if(dx==-1)l1=x-1;else l1=n-x;
        if(dy==-1)l2=y-1;else l2=m-y;
        l=min(l1,l2);
        x+=dx*l;y+=dy*l;ans+=l;
        if(l1==l)dx*=-1;if(l2==l)dy*=-1;
    }
    printf("-1\n");
}