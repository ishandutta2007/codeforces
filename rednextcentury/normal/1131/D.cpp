#include<bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
typedef long long ll;
typedef double ld;
typedef pair<int,int> p2;
typedef pair<p2,int> p3;
typedef vector<ll> vi;
const ll Mod = 7 + 1e9;
const ll INF32 = 5 + 2e9;
const ll INF64 = 1 + 1e18;
const ll MAX = 5+ 1e3;

int N,M,parent[2*MAX],dp[2*MAX];
vi G[2*MAX];
set<int> GG[2*MAX];
bool eq[2*MAX][2*MAX];
int vis[2*MAX];
// add b child (orginal graph)  to a (new Graph)
void merge(int a,int b)
{
    parent[b] = a;
}

// searching for cycles in new graph
bool IsCycled(int u)
{
    vis[u] = 1;
    for(int v : GG[u])
        if( vis[ parent[v] ] == 2 )
            continue;
        else if( vis[ parent[v]] == 1 || IsCycled( parent[v] ) )
            return 1;
    vis[u] = 2;
    return 0;
}
// dp function to find longest path in DAG
int Try(int u)
{
    int &r = dp[u];
    if( r != -1 )
        return r;
    r = 1;
    for(int v : GG[u])
        r = max(r,Try(v)+1);
    return r;
}
char inp[2001][2001];
int main()
{
    cin >> N >> M;
    for(int i=0; i<N; i++)
        for(int j=N; j<N+M; j++)
        {
            char c; cin >> c;
            inp[i][j]=c;
            if( c == '<' )
                G[j].push_back(i);
            else if( c == '>' )
                G[i].push_back(j);
            else eq[i][j] = 1;
        }
    // initializing indexes between original graph and new graph
    for(int i=0; i<N+M; i++) parent[i] = i;
    for(int j=N;j<N+M;j++)
    {
        int f = -1;
        for(int i=0;i<N;i++)
        if( eq[i][j] )
            f == -1 ? f = i : eq[f][i] = 1;
    }
    for(int i=0; i<N+M; i++)
    {
        // checking if this edges is added to new graph
        if( parent[i] == i )
            merge(i,i);
        for(int j=i+1; j<N+M; j++)
            if( eq[i][j] )
                merge( parent[i], j );
    }
    for (int i=0;i<N;i++)
    {
        for (int j=N;j<N+M;j++)
        {
            char c = inp[i][j];
            if( c == '<' )
                GG[parent[j]].insert(parent[i]);
            else if( c == '>' )
                GG[parent[i]].insert(parent[j]);
        }
    }
    for(int i=0; i<N+M; i++)
        if( !vis[ parent[i] ] )
        {
            if( IsCycled( parent[i] ) )
                return cout << "No\n",0;
        }
    memset(dp,-1,sizeof(dp));
    cout << "Yes\n" ;
    for(int i=0; i<N; i++)
        cout << Try( parent[i] ) << ' ';
    cout << endl;
    for(int i = N; i<N+M; i++)
        cout << Try( parent[i] ) << ' ';
    cout << endl;

    return 0;
}