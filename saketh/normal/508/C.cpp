#include <iostream>
#include <deque>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int M, T, R, C;
int w[305];

map<int, bool> lit;
deque<int> cndl;

int main(){
    cin >> M >> T >> R;
    for(int i=0; i<M; i++)
        cin >> w[i];

    if(R > T){ cout << -1 << endl; return 0; }

    for(int i=0; i<M; i++){
        int j = w[i];
        while(cndl.size() > 0 && j - cndl.front() >= T) cndl.pop_front();

        vector<int> to_light;

        for(int k=j; cndl.size() + to_light.size() < R; k--){
            if(j-k >= T){ cout << -1 << endl; return 0; }

            if(lit[k]) continue;
            lit[k] = true;
            C++;
            to_light.push_back(k);
        }

        reverse(to_light.begin(), to_light.end());
        for(int k : to_light) cndl.push_back(k);
    }

    cout << C << endl;
}