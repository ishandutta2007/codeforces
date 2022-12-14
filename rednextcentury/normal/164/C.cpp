//Works for negative costs, but does not work for negative cycles
//Complexity: O(min(E^2 *V log V, E logV * flow))
#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int to, flow, cap, cost, rev , id;
};

struct MinCostMaxFlow
{
	int nodes;
	vector<int> prio, curflow, prevedge, prevnode, q, pot;
	vector<bool> inqueue;
	vector<vector<edge> > graph;
	MinCostMaxFlow() {}

	MinCostMaxFlow(int n): nodes(n), prio(n, 0), curflow(n, 0),
	prevedge(n, 0), prevnode(n, 0), q(n, 0), pot(n, 0), inqueue(n, 0), graph(n) {}

	void addEdge(int source, int to, int capacity, int cost, int id)
	{
		edge a = {to, 0, capacity, cost, (int)graph[to].size(),id};
		edge b = {source, 0, 0, -cost, (int)graph[source].size(),-1};
		graph[source].push_back(a);
		graph[to].push_back(b);
	}

	void bellman_ford(int source, vector<int> &dist)
	{
		fill(dist.begin(), dist.end(), INT_MAX);
		dist[source] = 0;
		int qt=0;
		q[qt++] = source;
		for(int qh=0;(qh-qt)%nodes!=0;qh++)
		{
			int u = q[qh%nodes];
			inqueue[u] = false;
			for(auto &e : graph[u])
			{
				if(e.flow >= e.cap)
					continue;
				int v = e.to;
				int newDist = dist[u] + e.cost;
				if(dist[v] > newDist)
				{
					dist[v] = newDist;
					if(!inqueue[v])
					{
						inqueue[v] = true;
						q[qt++ % nodes] = v;
					}
				}
			}
		}
	}

	pair<int, int> minCostFlow(int source, int dest, int maxflow)
	{
		bellman_ford(source, pot);
		int flow = 0;
		int flow_cost = 0;
		while(flow < maxflow)
		{
			priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
			q.push({0, source});
			fill(prio.begin(), prio.end(), INT_MAX);
			prio[source] = 0;
			curflow[source] = INT_MAX;
			while(!q.empty())
			{
				int d = q.top().first;
				int u = q.top().second;
				q.pop();
				if(d != prio[u])
					continue;
				for(int i=0;i<graph[u].size();i++)
				{
					edge &e=graph[u][i];
					int v = e.to;
					if(e.flow >= e.cap)
						continue;
					int newPrio = prio[u] + e.cost + pot[u] - pot[v];
					if(prio[v] > newPrio)
					{
						prio[v] = newPrio;
						q.push({newPrio, v});
						prevnode[v] = u;
						prevedge[v] = i;
						curflow[v] = min(curflow[u], e.cap - e.flow);
					}
				}
			}
			if(prio[dest] == INT_MAX)
				break;
			for(int i=0;i<nodes;i++)
				pot[i]+=prio[i];
			int df = min(curflow[dest], maxflow - flow);
			flow += df;
			for(int v=dest;v!=source;v=prevnode[v])
			{
				edge &e = graph[prevnode[v]][prevedge[v]];
				e.flow += df;
				graph[v][e.rev].flow -= df;
				flow_cost += df * e.cost;
			}
		}
		return {flow, flow_cost};
	}
};

map<int,int> mp;
int l[1000000];
int r[1000000];
int c[1000000];
bool taken[1000000];
int main()
{
    int n,k;
    cin>>n>>k;
    set<int> s;
    for (int i=0;i<n;i++)
    {
        cin>>l[i]>>r[i]>>c[i];
        r[i]=l[i]+r[i];
        c[i]=-c[i];
        s.insert(l[i]);
        s.insert(r[i]);
    }
    int cur=1;
    for (auto x:s)mp[x]=cur++;
    int source=0,sink=cur;
    MinCostMaxFlow G(sink+1);
    for (int i=1;i+1<sink;i++)
        G.addEdge(i,i+1,k,0,-1);
    G.addEdge(source,1,k,0,-1);
    G.addEdge(sink-1,sink,k,0,-1);
    for (int i=0;i<n;i++)
        G.addEdge(mp[l[i]],mp[r[i]],1,c[i],i);
    auto ret = G.minCostFlow(source,sink,k);
    for (int i=0;i<=sink;i++)
    {
        for (auto e:G.graph[i]){
            if (e.id >= 0 && e.flow>0)taken[e.id]=1;
        }
    }
    for (int i=0;i<n;i++)cout<<taken[i]<<' ';
    cout<<endl;
}