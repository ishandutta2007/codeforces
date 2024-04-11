#include <iostream>
#include <set>
#include <vector>
using namespace std;

int sp[2000005];

int N, Q, A, B, T, I, V;
int val[100005], ans[100005], dep[100005];
vector<int> adj[100005];
set<pair<int, int> > hit[2000005];

void dfs(int loc = 0, int par = -1){
    if(par != -1) dep[loc] = dep[par] + 1;
    pair<int, int> here = make_pair(dep[loc], loc);

    int depth = -1;
    ans[loc] = -1;

    for(int v = val[loc]; v>1; v/=sp[v])
        if(hit[sp[v]].size()>0 && hit[sp[v]].rbegin()->first > depth){
            depth = hit[sp[v]].rbegin()->first;
            ans[loc] = hit[sp[v]].rbegin()->second;
        }

    for(int v = val[loc]; v>1; v/=sp[v])
        hit[sp[v]].insert(here);

    for(int i=0; i<adj[loc].size(); i++)
        if(adj[loc][i] != par)
            dfs(adj[loc][i], loc);

    for(int v = val[loc]; v>1; v/=sp[v])
        hit[sp[v]].erase(here);
}

int main(){
    ios_base::sync_with_stdio(false);

    for(int p=2; p<=2000000; p++)
        if(sp[p]) continue;
        else for(int q=p; q<=2000000; q+=p)
            sp[q] = p;

    cin >> N >> Q;
    for(int i=0; i<N; i++)
        cin >> val[i];

    for(int i=0; i<N-1; i++){
        cin >> A >> B;
        adj[A-1].push_back(B-1);
        adj[B-1].push_back(A-1);
    }

    dfs();

    for(int i=0; i<Q; i++){
        cin >> T;
        if(T == 1){
            cin >> I;
            if(ans[I-1] == -1) cout << -1 << "\n";
            else cout << ans[I-1]+1 << "\n";
        }
        else{
            cin >> I >> V;
            val[I-1] = V;
            dfs();
        }
    }

    cout.flush();
    return 0;
}