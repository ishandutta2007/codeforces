#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, m;

vector< pair<int,int> > g[N];
struct Nod {
	int u,f1,f2;
	LL dis;
	bool operator<(const Nod&o)const{
		return dis>o.dis;
	}
};
LL d[N][2][2];

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
	}	
	memset(d,-1,sizeof(d));
	priority_queue<Nod> q;
	q.push((Nod){1,0,0,0}); d[1][0][0]=0;
	while(q.size()){
		Nod now=q.top(); q.pop();
		if(now.dis > d[now.u][now.f1][now.f2])continue;

		int u=now.u,f1=now.f1,f2=now.f2;
		for(auto e:g[u]){
			for(int n1=f1;n1<=1;n1++){
				for(int n2=f2;n2<=1;n2++){
					LL nex=now.dis + e.second;
					int v=e.first;
					if(f1==0 && n1==1) nex-=e.second;
					if(f2==0 && n2==1) nex+=e.second;
					if(d[v][n1][n2]==-1 || d[v][n1][n2]>nex){
						d[v][n1][n2]=nex;
						q.push((Nod){v,n1,n2,nex});
					}
				}
			}
		}
	}
	for(int i=2;i<=n;i++){
		printf("%lld ", d[i][1][1]);
	}
}