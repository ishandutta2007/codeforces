#include <iostream>
#include <vector>
using namespace std;

int N, V, K, A;
vector<int> ans;

int main(){
    cin >> N >> V;
    for(int i=0; i<N; i++){
        cin >> K;
        bool go = false;
        for(int j=0; j<K; j++){
            cin >> A;
            go |= A < V;
        }
        if(go) ans.push_back(i+1);
    }

    cout << ans.size() << "\n";
    for(int s : ans) cout << s << " ";
    cout << endl;
    return 0;
}