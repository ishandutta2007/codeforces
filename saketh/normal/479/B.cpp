#include <iostream>
#include <set>
#include <vector>
using namespace std;

int N, K, V;
set<pair<int, int> > towers;
vector<pair<int, int> > moves;

int main(){
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> V;
        towers.insert(make_pair(V, i));
    }

    if(N == 1){ cout << "0 0" << endl; return 0; }

    for(int i=0; i<K; i++){
        pair<int, int> low = *towers.begin();
        pair<int, int> high = *--towers.end();
        if(high.first - low.first < 2) break;
    
        moves.push_back(make_pair(high.second, low.second));
        towers.erase(low);
        towers.insert(make_pair(low.first+1, low.second));
        towers.erase(high);
        towers.insert(make_pair(high.first-1, high.second));
    }

    cout << (--towers.end())->first - towers.begin()->first;
    cout << " " << moves.size() << "\n";
    for(int i=0; i<moves.size(); i++)
        cout << moves[i].first+1 << " " << moves[i].second+1 << "\n";
    cout.flush();
    return 0;
}