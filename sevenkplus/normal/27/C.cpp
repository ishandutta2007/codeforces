#include<cstdio>
#include<set>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[111111],b[111111];
void ff()
{
    set<int> p;map<int,int> q;
    memset(b,0,sizeof b);
    for(int i=1;i<=n;i++)
    {
        set<int>::iterator x=p.lower_bound(a[i]);
        if(x!=p.begin()){x--;b[i]=q[*x];}
        p.insert(a[i]),q[a[i]]=i;;
    }
    p.clear();q.clear();
    for(int i=1;i<=n;i++)
    {
        set<int>::iterator x=p.upper_bound(a[i]);
        if(x==p.end()){if(b[i])p.insert(a[i]);q[a[i]]=i;}
        else printf("3\n%d %d %d\n",b[q[*x]],q[*x],i),exit(0);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);ff();
    for(int i=1;i<=n;i++)a[i]=-a[i];ff();
    puts("0");
    return 0;
}