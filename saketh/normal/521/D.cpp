#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int K, N, M;

int init[100005];
int type[100005];

map<int, pair<int, int> > res;
map<int, vector<pair<int, int> > > adds;
vector<pair<double, int> > all;

vector<pair<int, int> > fin;

void proc(int i){
    if(res.count(i) && res[i].first > init[i])
        adds[i].push_back(make_pair(res[i].first - init[i], res[i].second));

    if(!adds.count(i)) return;

    sort(adds[i].begin(), adds[i].end());
    reverse(adds[i].begin(), adds[i].end());

    double val = init[i] + 1e-7;
    for(auto p : adds[i]){
        all.emplace_back( (val + p.first) / val, p.second);
        val += p.first;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> K >> N >> M;

    for(int i=1; i<=K; i++)
        cin >> init[i];

    for(int i=1; i<=N; i++){
        int T, I, B;
        cin >> T >> I >> B;
        
        type[i] = T;
        
        if(T == 1){
            if(!res.count(I) || res[I].first < B)
                res[I] = make_pair(B, i);
        }
        else if(T == 2)
            adds[I].push_back(make_pair(B, i));
        else{
            all.push_back(make_pair(B, i));
        }
    }

    for(int i=1; i<=K; i++)
        proc(i);

    sort(all.begin(), all.end());
    
    for(int i=((int)(all.size()))-1; i>=max(0, (int)(all.size()-M)); i--){
        if(all[i].first < 1) break;
        fin.push_back(make_pair(type[all[i].second], all[i].second));
    }

    sort(fin.begin(), fin.end());
    cout << fin.size() << endl;
    for(auto p : fin)
        cout << p.second << " ";
    cout << endl;
}