#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
typedef pair<PII,int> PI3;
#define mp make_pair
#define m3(a,b,c) mp(mp(a,b),c)
#define pb push_back
#define fi first
#define se second
#define _x fi.fi
#define _y fi.se
#define _z se
queue<PI3> q;PI3 pr[510][510][2];bool v[510][510][2];int n,m;vector<int> a[510];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0,x,y;i<m;i++)
        scanf("%d%d",&x,&y),--x,--y,
        a[x].pb(y),a[y].pb(x);
    q.push(m3(0,n-1,0)),
    v[0][n-1][0]=1,
    pr[0][n-1][0]=m3(-1,-1,-1);
    while(!q.empty())
    {
        PI3 x=q.front();q.pop();
        if(x._z==0)
        {
            for(vector<int>::iterator i=a[x._x].begin();i!=a[x._x].end();i++)
                if(!v[*i][x._y][1])q.push(m3(*i,x._y,1)),v[*i][x._y][1]=1,pr[*i][x._y][1]=x;
        }else
        {
            for(vector<int>::iterator i=a[x._y].begin();i!=a[x._y].end();i++)
                if(*i!=x._x&&!v[x._x][*i][0])q.push(m3(x._x,*i,0)),v[x._x][*i][0]=1,pr[x._x][*i][0]=x;
        }
    }
    if(!v[n-1][0][0])puts("-1");else
    {
        vector<int> S,T;
        PI3 w=m3(n-1,0,0);
        while(w!=m3(0,n-1,0))
        {
            if(w._z)S.pb(w._x);else T.pb(w._y);
            w=pr[w._x][w._y][w._z];
        }
        S.pb(0),T.pb(n-1),
        reverse(S.begin(),S.end()),
        reverse(T.begin(),T.end());
        printf("%d\n",(int)S.size()-1);
        for(int i=0;i<(int)S.size();i++)
            printf("%d%c",S[i]+1,i==(int)S.size()-1?'\n':' ');
        for(int i=0;i<(int)T.size();i++)
            printf("%d%c",T[i]+1,i==(int)T.size()-1?'\n':' ');
    }
    return 0;
}