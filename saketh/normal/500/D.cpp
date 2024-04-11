#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 100005;

int N, M;
vector<int> adj[MAXN];
int a[MAXN], b[MAXN], w[MAXN];
double prob[MAXN];
double ans = 0;
int dep[MAXN], subt[MAXN];

int dfs(int loc = 0, int here = 0, int par = -1){
    subt[loc] = 1;
    dep[loc] = here;
    for(int c : adj[loc]){
        if(c == par) continue;
        subt[loc] += dfs(c, here+1, loc);
    }
    return subt[loc];
} 

int main(){
    scanf("%d", &N);
    M = N-1;

    for(int i=0; i<M; i++){
        scanf("%d%d%d", &a[i], &b[i], &w[i]);
        a[i]--, b[i]--;
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }

    dfs();

    for(int i=0; i<M; i++){
        int low = (dep[a[i]]>dep[b[i]])?subt[a[i]]:subt[b[i]];

        prob[i] = low;
        prob[i] *= N-low;
        prob[i] /= N;
        prob[i] /= N-1;
        prob[i] *= 2;

        ans += prob[i] * w[i];
    }

    int Q, E, NW;
    scanf("%d", &Q);

    for(int i=0; i<Q; i++){
        scanf("%d%d", &E, &NW);
        E--;

        ans -= prob[E] * w[E];
        w[E] = NW;
        ans += prob[E] * w[E];
           
        printf("%.10f\n", 3*ans);
    }

    return 0;
}