#include <iostream>
using namespace std;


string all[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
string inp;

int main(){
    ios_base::sync_with_stdio(false);
    int N; cin >> N;
    cin >> inp;

    for(int i=0; i<8; i++){
        if(inp.size() != all[i].size()) continue;

        bool match = true;
        for(int j=0; j<inp.size(); j++)
            match &= inp[j]=='.' || inp[j]==all[i][j];
        if(match){ cout << all[i] << endl; return 0; }
    }
}