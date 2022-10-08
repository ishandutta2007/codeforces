#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
#define pb push_back
#define fi first
#define se second
map<int,vector<int> > a;set<int> c;vector<int> b;int n;
void ff(int x)
{
    c.insert(x),b.pb(x);
    for(vector<int>::iterator i=a[x].begin();i!=a[x].end();i++)
        if(c.find(*i)==c.end())ff(*i);
}
int main()
{
    scanf("%d",&n);
    for(int i=0,x,y;i<n;i++)
        scanf("%d%d",&x,&y),a[x].pb(y),a[y].pb(x);
    for(map<int,vector<int> >::iterator i=a.begin();i!=a.end();i++)
        if((int)i->se.size()==1){ff(i->fi);break;}
    for(int i=0;i<(int)b.size();i++)
        printf("%d%c",b[i],i==(int)b.size()-1?'\n':' ');
    return 0;
}