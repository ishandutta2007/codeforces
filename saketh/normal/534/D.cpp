#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
queue<int> f[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N; i++){
        int v;
        cin >> v;
        f[v].push(i+1);
    }

    vector<int> res;

    int R = 0;
    for(int i=0; i<N; i++){
        while(!f[R].size()){
            if(R < 3){
                cout << "Impossible\n";
                return 0;
            }
            R -= 3;
        }
        
        res.push_back(f[R].front());
        f[R].pop();
        R++;
    }

    cout << "Possible\n";
    for(int v : res) cout << v << " ";
    cout << endl;
}