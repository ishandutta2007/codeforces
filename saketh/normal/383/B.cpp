#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

int N, V, X, Y;
map<int, set<int> > volc;
set<pair<int, int> > reach;

set<pair<int, int> >::iterator updit(pair<int, int> v){
    reach.insert(v);
    return reach.lower_bound(v);
}

int main(){
    cin >> N >> V;
    for(int i=0; i<V; i++){
        cin >> X >> Y;
        volc[Y-1].insert(X-1);
    }
    volc[N-1].insert(-1);

    reach.insert(make_pair(0, 0));
    int last = -1;
    for(map<int, set<int> >::iterator it = volc.begin(); it!=volc.end(); it++){
        if(reach.size() == 0) break;
        
        if(it->first != last+1){
            int row = reach.begin()->first;    
            reach.clear();
            reach.insert(make_pair(row, N-1));
        }

        it->second.insert(N);        
        set<int>::iterator vol = it->second.begin();
        set<pair<int, int> >::iterator rng = reach.begin();

        while(rng != reach.end()){
            while(*vol < rng->first) vol++;
           
            while(rng->second < (*vol - 1)){
                if(next(rng) == reach.end() || next(rng)->first >= *vol){
                    pair<int, int> cur = *rng;
                    reach.erase(rng);
                    rng = updit(make_pair(cur.first, *vol - 1));
                }
                else{
                    pair<int, int> cur = *rng, nxt = *next(rng);
                    reach.erase(cur);
                    reach.erase(nxt);
                    rng = updit(make_pair(cur.first, nxt.second));
                }
            }
            
            if(rng->second >= *vol){
                pair<int, int> cur = *rng;
                reach.erase(rng);
                if(*vol + 1 <= cur.second)
                    reach.insert(make_pair(*vol + 1, cur.second));
                rng = updit(make_pair(cur.first, *vol - 1));
            }
            rng++;
        }

        for(set<pair<int, int> >::iterator it = reach.begin(); it != reach.end(); ){
            if(it->second < it->first) reach.erase(it++);
            else it++;
        }
        last = it->first;
    }

    if(reach.size() && (--reach.end())->second == N-1) cout << 2 * N - 2 << endl;
    else cout << -1 << endl;
    return 0;
}