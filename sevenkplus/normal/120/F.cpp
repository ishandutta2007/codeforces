#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define pb push_back
vector<vector<int> > a;
int ff(int x,int y,int z)
{
    int T=z;
    for(vector<int>::iterator i=a[x].begin();i!=a[x].end();i++)
        if(*i!=y)T=max(T,ff(*i,x,z+1));
    return T;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int _,S=0;scanf("%d",&_);
    while(_--)
    {
        int n;scanf("%d",&n);
        a.clear(),a.resize(n);
        for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),--x,--y,a[x].pb(y),a[y].pb(x);
        int T=0;
        for(int i=0;i<n;i++)T=max(T,ff(i,-1,0));
        S+=T;
    }
    printf("%d\n",S);
    return 0;
}