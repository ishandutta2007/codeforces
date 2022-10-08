#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
#define pb push_back
#define N 333
int le[N],ri[N],fa[N],n;vector<int> s,a[N];
void ff(int x)
{
    static int t=0;
    le[x]=++t;
    for(vector<int>::iterator i=a[x].begin();i!=a[x].end();i++)
        if(*i!=fa[x])fa[*i]=x,ff(*i);
    ri[x]=++t;
}
bool cnt(int x,int y)
{
    return le[x]<=le[y]&&ri[y]<=ri[x];
}
void gg(int x,int y)
{
    while(!cnt(x,y))x=fa[x],s.pb(x);
    vector<int> t;
    while(!cnt(y,x))t.pb(y),y=fa[y];
    reverse(t.begin(),t.end());
    for(int i=0;i<(int)t.size();i++)s.pb(t[i]);
}
int main()
{
    scanf("%d",&n);
    for(int i=1,x,y;i<n;i++)
        scanf("%d%d",&x,&y),
        a[x].pb(y),a[y].pb(x);
    ff(1);s.pb(1);
    int k,la;
    scanf("%d",&k);gg(1,k),la=k;
    while(scanf("%d",&k)!=EOF)
    {
        gg(la,k);
        if((int)s.size()>n*2-1){puts("-1");return 0;}
        la=k;
    }
    gg(la,1);
    if((int)s.size()!=n*2-1){puts("-1");return 0;}
    for(int i=0;i<(int)s.size();i++)
        printf("%d%c",s[i],i==(int)s.size()-1?'\n':' ');
    return 0;
}