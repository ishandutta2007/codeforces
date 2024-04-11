#include <cstdio>
#include <set>
#include <vector>
using namespace std;

const int MAXN = 100000;

int N, M;
vector<pair<int, int> > adj[MAXN+5];
bool block[MAXN];

int go(int loc){
    vector<int> nbr, um;

    for(pair<int, int> n : adj[loc]){
        if(block[n.second]) continue;
        nbr.push_back(n.first);
        block[n.second] = true;
    }

    for(int n : nbr){
        int unm = go(n);
        if(unm == -1) um.push_back(n);
        else printf("%d %d %d\n", loc+1, n+1, unm+1);
    }

    for(int i=0; i+1<um.size(); i+=2)
        printf("%d %d %d\n", um[i]+1, loc+1, um[i+1]+1);
    
    if(um.size() % 2) return um.back();
    return -1;
}

int main(){
    scanf("%d %d", &N, &M);
    if(M%2){ printf("No solution\n"); return 0; }
    
    for(int i=0; i<M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        adj[a].push_back(make_pair(b, i));
        adj[b].push_back(make_pair(a, i));
    }

    go(0);
    return 0;
}