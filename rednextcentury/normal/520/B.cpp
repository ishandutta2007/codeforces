#include<queue>
# include <iostream>
# include <vector>
# include <cstring>
using namespace std;
#define MAX 20005

int main() {

int n,m;

vector<int> adj_list[MAX];
bool visited[MAX];
int dist[MAX];

cin>>n>>m;

memset(visited,0,sizeof visited);
memset(dist,0,sizeof dist);

queue <int> Q;
int u;
Q.push(n);
visited[n]=1;

while(!Q.empty())
{
    u=Q.front();
    Q.pop();
    if(u==m) break;
    int v;

    v=2*u;
    if(v<=2*m && !visited[v])
    {
        //cout<<v<<endl;
        Q.push(v);
        visited[v]=1;
        dist[v]=dist[u]+1;
    }

    v=u-1;
    if(v>0 && !visited[v])
    {
        //cout<<v<<endl;
        Q.push(v);
        visited[v]=1;
        dist[v]=dist[u]+1;
    }
}

cout<<dist[m];

return 0;
}