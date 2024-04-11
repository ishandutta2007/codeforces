#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, string> > pp;
vector<string> ranked;
unordered_map<string, int> ranks;

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        string name;
        int front;
        cin >> name >> front;
        pp.emplace_back(front, name);
    }

    sort(pp.begin(), pp.end());
    for(auto p : pp){
        if(p.first > ranked.size()){
            cout << -1 << endl;
            return 0;
        }

        ranked.insert(ranked.begin() + p.first, p.second);
    }

    for(int i=0; i<ranked.size(); i++)
       ranks[ranked[i]] = ranked.size() - i;

    for(auto p : pp)
        cout << p.second << " " << ranks[p.second] << "\n"; 
}