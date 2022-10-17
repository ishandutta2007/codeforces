#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;

void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}

const int MAXM = 100005;

int N, M, D;
int ind[2*MAXM];
vector<int> adj[2*MAXM];

int main(){
    setup();

    cin >> N >> M;
    D = M;

    for(int r=0; r<N; r++){
        vector<pair<int, int> > row;
        
        for(int j=0; j<M; j++){
            int v; cin >> v;
            if(v == -1) continue;
            row.emplace_back(v, j);
        }
        
        sort(row.begin(), row.end());
    
        vector<vector<int> > grps;    
        for(int i=0; i<row.size(); ){
            grps.push_back(vector<int>());
            int j = i;
            for(; j<row.size(); j++){
                if(row[j].first != row[i].first) break;
                grps.back().push_back(row[j].second);
            }
            i = j;
        }

        for(int g=1; g<grps.size(); g++){
            int NV = D++;
            ind[NV] = grps[g-1].size();
            for(int v : grps[g-1])
                adj[v].push_back(NV);
            for(int v : grps[g]){
                adj[NV].push_back(v);
                ind[v]++;
            }
        }
    }

    vector<int> topo;
    queue<int> noinp;

    for(int i=0; i<D; i++)
        if(ind[i] == 0)
            noinp.push(i);

    while(!noinp.empty()){
        int vert = noinp.front();
        noinp.pop();
        topo.push_back(vert);
        for(int nbr : adj[vert]){
            ind[nbr]--;
            if(!ind[nbr]) noinp.push(nbr);
        }
    }

    if(topo.size() == D){
        for(int v : topo)
            if(v < M)
                cout << v+1 << " ";
        cout << endl;
    }
    else cout << -1 << endl;
}