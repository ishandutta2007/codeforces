#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}

const int MAXN = 100100;
const int INF = 1e9;

int N, M, D, A;
vector<int> adj[MAXN];
bool evil[MAXN];
int fes[MAXN];

int prep(int loc, int par){
    for(int ch : adj[loc])
        if(ch != par){
            int res = prep(ch, loc);
            if(res != -INF)
                fes[loc] = max(fes[loc], 1+res);
        } 

    if(evil[loc]) fes[loc] = max(fes[loc], 0);
    return fes[loc];
}

void calc(int loc, int par, int abv){
    if(fes[loc] <= D && abv <= D) A++; 

    int mcf = -INF, idx = -1; 
    for(int i=0; i<adj[loc].size(); i++)
        if(adj[loc][i] != par && fes[adj[loc][i]] > mcf){
            mcf = fes[adj[loc][i]];
            idx = i;
        }

    if(abv != -INF) abv++;
    if(evil[loc]) abv = max(abv, 1);

    for(int i=0; i<adj[loc].size(); i++){
        if(adj[loc][i] == par) continue;
        if(i != idx){
            int nabv = abv;
            if(mcf != -INF) nabv = max(nabv, mcf+2);            
            calc(adj[loc][i], loc, nabv);
        }
        else{
            int nabv = abv;
            for(int j=0; j<adj[loc].size(); j++)
                if(j != idx && adj[loc][j] != par)
                    nabv = max(nabv, fes[adj[loc][j]]+2);
            calc(adj[loc][i], loc, nabv);
        }
    }
}

int main(){
    setup();
    cin >> N >> M >> D;
   
    for(int i=0; i<M; i++){
        int u;
        cin >> u;
        evil[u-1] = true;
    }
 
    for(int i=1; i<N; i++){
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    for(int &v : fes)
        v = -INF;        

    prep(0, -1);
    calc(0, -1, -INF);

    cout << A << endl;
}