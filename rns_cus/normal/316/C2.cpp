#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef int F;
typedef int C;
#define F_INF (1<<29)
#define C_INF (1<<29)
#define MAXV 10000
#define MAXE 200000 // E*2!

int V,E;
F cap[MAXE];
C cost[MAXE],dist[MAXV],pot[MAXV];
int to[MAXE],prev[MAXE],last[MAXV],path[MAXV];
bool used[MAXV];
deque <pair <C, int> > q;

class MinCostFlow{
    public:

    MinCostFlow(int n){
        int i;
        V = n; E = 0;
        REP(i,V) last[i] = -1;
    }

    void add_edge(int x, int y, F w, C c){
        cap[E] = w; cost[E] = c; to[E] = y; prev[E] = last[x]; last[x] = E; E++;
        cap[E] = 0; cost[E] = -c; to[E] = x; prev[E] = last[y]; last[y] = E; E++;
    }

    pair <F, C> search(int s, int t){
        F ansf=0; C ansc=0;
        int i;

        REP(i,V) used[i] = false;
        REP(i,V) dist[i] = C_INF;

        dist[s] = 0; path[s] = -1; q.push_front(make_pair(0,s));
        while(!q.empty()){
            int x = q[0].second; q.pop_front();
            if(used[x]) continue; used[x] = true;
            for(int e=last[x];e>=0;e=prev[e]) if(cap[e] > 0){
                C tmp = dist[x] + cost[e] + pot[x] - pot[to[e]];
                if(tmp < dist[to[e]] && !used[to[e]]){
                    dist[to[e]] = tmp;
                    path[to[e]] = e;
                    if(cost[e] + pot[x] - pot[to[e]] == 0){
                        q.push_front(make_pair(-dist[to[e]],to[e]));
                    } else if(cost[e] + pot[x] - pot[to[e]] == 1){
                        q.push_back(make_pair(-dist[to[e]],to[e]));
                    }
                }
            }
        }

        REP(i,V) pot[i] += dist[i];

        if(used[t]){
            ansf = F_INF;
            for(int e=path[t];e>=0;e=path[to[e^1]]) ansf = min(ansf,cap[e]);
            for(int e=path[t];e>=0;e=path[to[e^1]]) {ansc += cost[e] * ansf; cap[e] -= ansf; cap[e^1] += ansf;}
        }

        return make_pair(ansf,ansc);
    }

    pair <F, C> mincostflow(int s, int t){
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

int X,Y;
int a[90][90];
int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};

int perm[7000];

int main(void){
    int i,j,k;

    cin >> X >> Y;
    REP(i,X) REP(j,Y) cin >> a[i][j];

/*  X = Y = 80;
    REP(i,6400) perm[i] = i/2;
    random_shuffle(perm, perm+6400);
    REP(i,X) REP(j,Y) a[i][j] = perm[i*80+j];
*/
    int S = X * Y;
    MinCostFlow mcf(S+2);

    REP(i,X) REP(j,Y){
        int id = i*Y+j;
        if(i%2 == j%2){
            mcf.add_edge(S, id, 1, 0);
            REP(k,4){
                int i2 = i+dx[k], j2 = j+dy[k];
                if(i2 >= 0 && i2 < X && j2 >= 0 && j2 < Y){
                    int id2 = i2*Y+j2;
                    mcf.add_edge(id, id2, 1, ((a[i][j] == a[i2][j2]) ? 0 : 1));
                }
            }
        } else {
            mcf.add_edge(id, S+1, 1, 0);
        }
    }

    int ans = mcf.mincostflow(S, S+1).second;
    cout << ans << endl;

    return 0;
}