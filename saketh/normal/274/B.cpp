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

const int MAXN = 100005;

int N;
vector<int> adj[MAXN];
ll val[MAXN];

pair<ll, ll> dfs(int loc, int par){
    ll pl = 0;
    ll sb = 0;

    for(int c : adj[loc])
        if(c != par){
            auto p = dfs(c, loc);
            pl = max(pl, p.first);
            sb = max(sb, p.second);
        }

    val[loc] += pl;
    val[loc] -= sb;

    if(val[loc] > 0) sb += val[loc];
    else pl -= val[loc];

    return {pl, sb};
}

int main(){
    setup();
    cin >> N;
    for(int i=1; i<N; i++){
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    for(int i=0; i<N; i++)
        cin >> val[i];

    auto f = dfs(0, -1);
    cout << f.first + f.second << endl;
}