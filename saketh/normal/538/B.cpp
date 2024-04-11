#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> digs, res;

int main(){
    cin >> N;
    
    while(N){
        digs.push_back(N%10);
        N /= 10;
    }

    reverse(digs.begin(), digs.end());

    for(int i=0; i<9; i++){
        int v = 0;
        
        for(int j=0; j<digs.size(); j++){
            v *= 10;
            if(digs[j]){
                v++;
                digs[j]--;
            }
        }

        if(!v) break;
        res.push_back(v);
    }

    cout << res.size() << endl;
    for(int v : res) cout << v << " ";
    cout << endl;
}