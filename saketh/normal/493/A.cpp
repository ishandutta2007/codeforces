#include <iostream>
#include <algorithm>
using namespace std;

string home, away;
int ev;

struct event{
    int time, player;
    char team, card;

    bool operator<(const event &y) const{
        return time < y.time;
    }
} all[128];

int st[2][128];

int main(){
    cin >> home >> away >> ev;
    for(int i=0; i<ev; i++){
        cin >> all[i].time >> all[i].team >> all[i].player >> all[i].card;
    }

    sort(all, all+ev);

    for(int i=0; i<ev; i++){
        bool t = all[i].team=='h';
        int j = all[i].player;
        bool r = all[i].card=='r';
    
        if(st[t][j] == 2) continue;

        if(r) st[t][j] = 2;
        else{ st[t][j]++; }
    
        if(st[t][j] == 2){
            if(all[i].team == 'h') cout << home << " ";
            else cout << away << " ";
            cout << all[i].player << " ";
            cout << all[i].time << "\n";
        }
    }

    cout.flush();
    return 0;
}