#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
typedef double typ;
#define mp make_pair
#define fi first
#define se second
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
typedef int F;
typedef double C;
#define F_INF (1<<29)
#define C_INF 1.0E+9
#define MAXV 900
#define MAXE 400000 // E*2!

int V,E;
F cap[MAXE];
C cost[MAXE],dist[MAXV],pot[MAXV];
int to[MAXE],prev[MAXE],last[MAXV],path[MAXV];
bool used[MAXV];
priority_queue <pair <C, int> > q;

class MinCostFlow{
    public:

    MinCostFlow(int n){
        int i;
        V = n; E = 0;
        rep(i,V) last[i] = -1;
    }

    void aedge(int x, int y, F w, C c){
        cap[E] = w; cost[E] = c; to[E] = y; prev[E] = last[x]; last[x] = E; E++;
        cap[E] = 0; cost[E] = -c; to[E] = x; prev[E] = last[y]; last[y] = E; E++;
    }

    pair <F, C> search(int s, int t){
        F ansf=0; C ansc=0;
        int i;

        rep(i,V) used[i] = false;
        rep(i,V) dist[i] = C_INF;
    
        dist[s] = 0; path[s] = -1; q.push(make_pair(0,s));
        while(!q.empty()){
            int x = q.top().second; q.pop();
            if(used[x]) continue; used[x] = true;
            for(int e=last[x];e>=0;e=prev[e]) if(cap[e] > 0){
                C tmp = dist[x] + cost[e] + pot[x] - pot[to[e]];
                if(tmp < dist[to[e]] && !used[to[e]]){
                    dist[to[e]] = tmp;
                    path[to[e]] = e;
                    q.push(make_pair(-dist[to[e]],to[e]));
                }
            }
        }

        rep(i,V) pot[i] += dist[i];

        if(used[t]){
            ansf = F_INF;
            for(int e=path[t];e>=0;e=path[to[e^1]]) ansf = min(ansf,cap[e]);
            for(int e=path[t];e>=0;e=path[to[e^1]]) {ansc += cost[e] * ansf; cap[e] -= ansf; cap[e^1] += ansf;}
        }

        return make_pair(ansf,ansc);
    }

    pair <F, C> mcmf(int s, int t){
        F ansf=0; C ansc=0;
        int i;
        while(1){
            pair <F, C> p = search(s,t);
            if(!used[t]) break;
            ansf += p.first; ansc += p.second;
        }
        return make_pair(ansf,ansc);
    }
};

int main()
{
	int i,j,n,my=-1100;int x[500],y[500];
	cin>>n;//v=2*n+2;
	MinCostFlow mcf(2*n+2);
	rep(i,n){
		cin>>x[i]>>y[i];my=max(my,y[i]);
	}
	rep(i,n){if(y[i]<my) mcf.aedge(n+i,n*2+1,1,0);mcf.aedge(n*2,i,2,0);}
	rep(i,n) rep(j,n){
		if(y[i]>y[j]) mcf.aedge(i,j+n,1,sqrt(1.0*(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
	}
	pair<F,C> out=mcf.mcmf(n*2,n*2+1);
	if(out.fi<n-1) cout<<"-1"<<endl;
	else printf("%.12f\n",out.se);
	return 0;
}