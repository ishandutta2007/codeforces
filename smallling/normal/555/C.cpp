#include<set>
#include<cstdio>

using namespace std;

int n,q,x[200010],y[200020];
set<pair<int,int> >a,flag;
char s[10];

int main()
{
    scanf("%d%d",&n,&q);
    a.insert(make_pair(0,0));
    a.insert(make_pair(n+1,0));
    set<pair<int,int> >::iterator it;
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d%s",&x[i],&y[i],s);
        if(flag.find(make_pair(x[i],y[i]))!=flag.end())
        {
            puts("0");
            continue;
        }
        flag.insert(make_pair(x[i],y[i]));
        if(s[0]=='U')it=--a.lower_bound(make_pair(y[i],0));
        else it=a.upper_bound(make_pair(y[i],0));
        a.insert(make_pair(y[i],i));
        if(s[0]=='U')printf("%d\n",y[i]-y[(*it).second]),y[i]=y[(*it).second];
        else printf("%d\n",x[i]-x[(*it).second]),x[i]=x[(*it).second];
    }
}