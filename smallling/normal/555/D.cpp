#include<map>
#include<set>
#include<cstdio>

using namespace std;

set<int>a;
map<int,int>where;
int n,m,now,l,X,fx,nowX,cnt,x[200020];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]),where[x[i]]=i,a.insert(x[i]);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&now,&l);
        X=x[now];
        fx=1;
        while(1)
        {
            if(fx)
            {
                nowX=*(--a.upper_bound(X+l));
                now=where[nowX];
                l-=(nowX-X);
                X=nowX;
                fx=0;
            }
            else
            {
                nowX=*(a.lower_bound(X-l));
                if(nowX==X)break;
                cnt=l/(2*(X-nowX));
                if(cnt)
                {
                    l-=cnt*2*(X-nowX);
                    continue;
                }
                l-=(X-nowX);
                now=where[nowX];
                X=nowX;
                fx=1;
            }
        }
        printf("%d\n",now);
    }
}