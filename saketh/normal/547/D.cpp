#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <string.h>
using namespace std;

const int INF = 200000;
const int MAXN = 200005;

int N, E;
int row[MAXN], col[MAXN];
int x[2 * MAXN], y[2 * MAXN];
int rob[2 * MAXN];
vector<int> adj[4 * MAXN];

void dfs(int st, int lo, int co){
    if(lo == st) return;
    
    while(rob[adj[lo].back()]) adj[lo].pop_back();
    int e = adj[lo].back();
    adj[lo].pop_back();
    
    rob[e] = co;
    int nl = (x[e]==lo) ? MAXN+y[e] : x[e];
    dfs(st, nl, 3-co);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
        col[x[i]]++;
        row[y[i]]++;        
    }

    E = N;
    for(int i=0; i<INF; i++){
        if(row[i] % 2){
            x[E] = INF;
            col[INF]++;
            y[E] = i;
            E++;
        }
        if(col[i] % 2){
            x[E] = i;
            y[E] = INF;
            row[INF]++;
            E++;
        }
    }

    if(row[INF] % 2){
        x[E] = INF;
        y[E] = INF;
        E++;
    }

    for(int e=0; e<E; e++){
        adj[x[e]].push_back(e);
        adj[MAXN+y[e]].push_back(e);
    }

    for(int e=0; e<E; e++){
        if(rob[e]) continue;
        rob[e] = 1; 
        dfs(x[e], MAXN+y[e], 2);
    }

    for(int i=0; i<N; i++)
        cout << (rob[i]-1 ? 'b' : 'r'); 
    cout << endl;
}