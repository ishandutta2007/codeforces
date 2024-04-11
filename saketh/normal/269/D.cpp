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

const int INF = 1e9;
const int MAXN = 1e5 + 100;
typedef pair<pair<int, int>, int> rng;

int N, T;
int ord[MAXN];
int lef[MAXN], rig[MAXN], ht[MAXN];

int rch[MAXN];
vector<pair<int, int> > succ[MAXN];

int main(){
    setup();
    cin >> N >> T;
    
    lef[0] = -INF, rig[0] = INF, ht[0] = 0; 
    for(int i = 1; i <= N; i++){
        cin >> ht[i] >> lef[i] >> rig[i];
    }   
    lef[N+1] = -INF, rig[N+1] = INF, ht[N+1] = T;
    N += 2;

    for(int i=0; i<N; i++) ord[i] = i;
    sort(ord, ord+N, [](int i, int j){ return ht[i] > ht[j]; });

    set<rng> front; 
    front.insert({{lef[0], rig[0]}, 0});    
    for(int j=1; j<N; j++){
        int i = ord[j];
        vector<rng> add, del;
        
        for(auto it = --front.lower_bound({{lef[i]+1, -INF}, -INF}); it != front.end(); it++){
            if(it->first.first > rig[i]) break;
            int ovl = min(rig[i], it->first.second) - max(lef[i], it->first.first); 

            if(ovl > 0){
                bool good = true;
                if(lef[i] < it->first.first && lef[ord[it->second]] < it->first.first){
                    good = false;
                }
                if(rig[i] > it->first.second && rig[ord[it->second]] > it->first.second){
                    good = false;
                }
                if(good) {
                    assert(it->second < j); 
                    succ[it->second].emplace_back(j, ovl);
                } 
            }

            auto nv = *it;                
            del.push_back(nv);
            if(nv.first.first < lef[i]) add.push_back({{nv.first.first, lef[i]}, nv.second});
            if(nv.first.second > rig[i]) add.push_back({{rig[i], nv.first.second}, nv.second});
        } 

        for(auto &p : del) front.erase(p);
        for(auto &p : add) front.insert(p);
        front.insert({{lef[i], rig[i]}, j});
    }

    rch[N-1] = 2e9;
    for(int i=N-2; i>=0; i--){
        for(auto e : succ[i]){
            if(i == 0 && e.first == N-1) continue;
            rch[i] = max(rch[i], min(e.second, rch[e.first]));
        }
    } 
    cout << rch[0] << endl;
}