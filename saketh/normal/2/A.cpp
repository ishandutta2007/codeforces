#include <iostream>
#include <unordered_map>
using namespace std;

const int MAXN = 1024;

int N, V, val[MAXN];
string name[MAXN];
unordered_map<string, int> score, when;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> name[i] >> val[i];
        score[name[i]] += val[i];
    }

    for(pair<string, int> p : score){
        string who = p.first;
        int tot = p.second;
        
        int cur = 0;
        for(int i=0; i<N; i++){
            if(name[i] == who) cur += val[i];
            if(cur >= tot){ when[who] = i; break; }
        }
    }

    string best = name[0];
    for(pair<string, int> p : score){
        if(p.second > score[best]) best = p.first;
        else if(p.second == score[best] && when[p.first] < when[best]) best = p.first;
    }

    cout << best << endl;
}