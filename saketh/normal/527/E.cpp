#include <iostream>
#include <vector>
#include <assert.h>
#include <string.h>
using namespace std;

const int MAXN = 100005;
const int MAXE = 300005;

int N, M;

bool used[MAXE];
int u[MAXE], v[MAXE];
vector<int> adj[MAXN];

vector<vector<int> > trail; // most hilarious way to get euler circuit

int refl(int e, int l){
    return u[e] + v[e] - l;
}

bool seen[MAXN];
int ent[MAXN];
vector<int> vis;

void find(){
    seen[0] = true;
    vis.push_back(0);

    for(int T = M; T; ){
        int cand = vis.back();
        while(adj[cand].size() && used[adj[cand].back()])
           adj[cand].pop_back(); 
        if(!adj[cand].size()){
            vis.pop_back();
            continue;
        }
        
        int loc = vis.back();
        ent[loc] = trail.size();
        trail.push_back(vector<int>(1, loc));

        while(adj[loc].size()){
            if(used[adj[loc].back()]){
                adj[loc].pop_back();
                continue;
            }
            
            int nbr = refl(adj[loc].back(), loc);
            used[adj[loc].back()] = true;
            T--;
            adj[loc].pop_back();

            if(!seen[nbr]){
                seen[nbr] = true;
                vis.push_back(nbr);
            }
            
            // wtf am i doing

            trail.back().push_back(nbr);
            loc = nbr;
        }
    }
}

bool print(int whr = 0, bool par = true){
    ent[trail[whr].front()] = -1;
    for(int i=1; i<trail[whr].size(); i++){
        int a = trail[whr][i-1];
        
        if(ent[a] != -1)
            par = print(ent[a], par);

        int b = trail[whr][i];
        if(par) cout << a+1 << " " << b+1 << "\n";
        else cout << b+1 << " " << a+1 << "\n";
        par = !par;
    }
    
    return par;
}

int main(){
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> u[i] >> v[i];
        adj[--u[i]].push_back(i);
        adj[--v[i]].push_back(i);
    }

    vector<int> odds;
    for(int i=0; i<N; i++)
       if(adj[i].size() & 1)
          odds.push_back(i);
   
    for(int i=0; i<odds.size(); i+=2){
        u[M] = odds[i];
        v[M] = odds[i+1];
        adj[u[M]].push_back(M);
        adj[v[M]].push_back(M);
        M++;
    } 
   
    if(M&1){
        u[M] = v[M] = 0;
        adj[0].push_back(M++);
    }   

    memset(ent, 0xff, sizeof(ent));
    find();
    cout << M << "\n";
    print();    
}