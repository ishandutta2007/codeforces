#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define N 100010
#define pb push_back
int n,m,d[N],S=0;vector<int> a[N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0,x,y;i<m;i++)
        scanf("%d%d",&x,&y),a[--x].pb(--y);
    memset(d,-1,sizeof d),d[0]=0;
    queue<int> q;q.push(0);
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(vector<int>::iterator i=a[x].begin();i!=a[x].end();i++)
            if(d[*i]!=-1)S=__gcd(S,abs(d[*i]-d[x]-1));
            else d[*i]=d[x]+1,q.push(*i);
    }
    vector<int> s;
    for(int i=0;i<n;i++)
        if(d[i]!=-1&&d[i]%S==0)s.pb(i+1);
    printf("%d\n%d\n",S,(int)s.size());
    for(int i=0;i<(int)s.size();i++)
        printf("%d%c",s[i],i==(int)s.size()-1?'\n':' ');
    return 0;
}