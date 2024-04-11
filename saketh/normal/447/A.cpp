#include <iostream>
using namespace std;

int P, N;
bool seen[400];

int main(){
    cin >> P >> N;
    for(int i=0; i<N; i++){
        int T; cin >> T; T %= P;
        if(seen[T]){ cout << i+1 << endl; return 0; }
        seen[T] = true;
    }

    cout << -1 << endl;
    return 0;
}