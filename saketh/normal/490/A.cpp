#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> v[3];

int main(){
    cin >> N;
    for(int i=0, t; i<N; i++){
        cin >> t;
        v[t-1].push(i+1);
    }

    cout << min(v[0].size(), min(v[1].size(), v[2].size())) << "\n";
    while(true){
        bool done = false;
        for(int i=0; i<3; i++)
            done |= !v[i].size();
        if(done) break;

        for(int i=0; i<3; i++){
            cout << v[i].front() << " ";
            v[i].pop();
        }

        cout << "\n";
    }

    cout.flush();
    return 0;
}