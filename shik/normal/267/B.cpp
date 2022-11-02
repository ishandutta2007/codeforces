// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int deg[7],vis[7];
vector<int> e[7][7];
vector< pair<int,char> > sol;
void dfs( int p ) {
    vis[p]=1;
    for ( int i=0; i<7; i++ ) {
        if ( !e[p][i].empty() ) {
            int eid=e[p][i].back();
            e[p][i].pop_back();
            dfs(i);
            sol.push_back(make_pair(eid,'+'));
        } else if ( !e[i][p].empty() ) {
            int eid=e[i][p].back();
            e[i][p].pop_back();
            dfs(i);
            sol.push_back(make_pair(eid,'-'));
        }
    }
}
int main()
{
    int m,a,b;
    scanf("%d",&m);
    for ( int i=1; i<=m; i++ ) {
        scanf("%d%d",&a,&b);
        e[a][b].push_back(i);
        deg[a]++; deg[b]++;
    }
    int odd=0,who=-1;
    for ( int i=0; i<7; i++ ) if ( deg[i]%2==1 ) odd++,who=i;
    if ( odd!=0 && odd!=2 ) return puts("No solution"),0;
    for ( int i=0; who==-1; i++ ) if ( deg[i]>0 ) who=i;
    dfs(who);
    for ( int i=0; i<7; i++ ) if ( deg[i]>0 && !vis[i] ) return puts("No solution"),0;
    reverse(sol.begin(),sol.end());
    FOR(it,sol) printf("%d %c\n",it->first,it->second);
    return 0;
}