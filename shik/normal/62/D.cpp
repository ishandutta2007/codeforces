// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 110
#define MM 2010
using namespace std;
vector<int> e[N];
int n,m,fa[N],tmt[N],path[MM],tbl[N][N];
int Find( int x ) { return fa[x]==x?x:fa[x]=Find(fa[x]); }
void Union( int a, int b ) { fa[Find(b)]=Find(a); }
bool is_con( int x, int a, int b ) {
    for ( int i=1; i<=n; i++ ) {
        fa[i]=i;
        tmt[i]=0;
    }
    for ( int i=x; i<m; i++ ) {
        if ( path[i]==a && path[i+1]==b ) continue;
        if ( path[i]==b && path[i+1]==a ) continue;
        Union(path[i],path[i+1]);
        tmt[path[i]]=tmt[path[i+1]]=1;
    }
    for ( int i=1; i<=n; i++ )
        if ( tmt[i] && Find(i)!=Find(path[0]) ) return 0;
    return 1;
}
int chk( int M ) {
    int p=path[M];
    for ( vector<int>::iterator it=e[p].begin(); it!=e[p].end(); it++ )
        if ( tbl[p][*it]>M+1 && *it>path[M+1] ) {
            if ( is_con(M,p,*it) ) return *it;
        }
    return 0;
}
int stk[MM],top=-1;
void go( int p ) {
    for ( int i=1; i<=n; i++ )
        if ( tbl[p][i] ) {
            tbl[p][i]=0;
            tbl[i][p]=0;
            go(i);
        }
    stk[++top]=p;
}
void output( int id, int xd ) {
    for ( int i=0; i<=id; i++ ) {
        printf("%d ",path[i]);
        if ( i<id ) {
            tbl[path[i]][path[i+1]]=0;
            tbl[path[i+1]][path[i]]=0;
        }
    }
    tbl[path[id]][xd]=0;
    tbl[xd][path[id]]=0;
    go(xd);
    for ( int i=top; i>=0; i-- ) printf("%d%c",stk[i],i==0?'\n':' ');
}
void add( int a, int b, int c ) {
    e[a].push_back(b);
    e[b].push_back(a);  
    tbl[a][b]=tbl[b][a]=c;
}
int main()
{
    int i;
    scanf("%d%d",&n,&m);
    for ( i=0; i<=m; i++ ) scanf("%d",path+i);
    for ( i=0; i<m; i++ ) add(path[i],path[i+1],i+1);
    for ( i=1; i<=n; i++ ) sort(e[i].begin(),e[i].end());
    for ( i=m-1; i>=0; i-- )
        if ( chk(i) ) {
            output(i,chk(i));
            break;  
        }
    if ( i<0 ) puts("No solution");
    return 0;
}