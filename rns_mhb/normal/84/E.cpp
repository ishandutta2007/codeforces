#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,string,int,int> node;
int n,m,k,S,T,dir[4]={1,-1};
char *grid;
inline int dis(int i,int j){return abs(i/m-j/m)+abs(i%m-j%m);}
string dijkstra()
{
    priority_queue<node,vector<node>,greater<node> > q;
    set<pair<int,int> > vis;
    q.push(make_tuple(dis(S,T),"",0,S));
    while(!q.empty())
    {
        auto c=q.top();
        string path=get<1>(c);
        int i=get<3>(c);
        int mask=get<2>(c);
        q.pop();
        if(vis.insert(make_pair(i,mask)).second)
            for(int j=0;j<4;j++)
            {
                int t=mask|(1<<(grid[i+dir[j]]-'a'));
                if(grid[i+dir[j]]=='S') continue;
                else if(grid[i+dir[j]]=='T') return path;
                else if(__builtin_popcount(t)<=k && !vis.count(make_pair(i+dir[j],t)))
                    q.push(make_tuple(dis(i+dir[j],T)+path.size()+1,path+grid[i+dir[j]],t,i+dir[j]));
            }
    }
    return "-1";
}
int main()
{
    cin>>n>>m>>k;n+=2,dir[3]=-(dir[2]=m+=2);
    grid=(char*)malloc(n*m);
    memset(grid,'S',n*m);
    for(int i=1;i<n-1;i++)
        for(int j=1;j<m-1;j++)
        {
            cin>>grid[i*m+j];
            if(grid[i*m+j]=='S') S=i*m+j;
            if(grid[i*m+j]=='T') T=i*m+j;
        }
    cout<<dijkstra()<<endl;
    return 0;
}