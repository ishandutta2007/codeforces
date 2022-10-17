#include <iostream>
using namespace std;

int N, P, Q, T;
bool can[105];

int main(){
    cin >> N;

    cin >> P;
    for(int i=0; i<P; i++){
        cin >> T;
        can[T-1] = true;
    }

    cin >> Q;
    for(int i=0; i<Q; i++){
        cin >> T;
        can[T-1] = true;
    }

    bool good = true;
    for(int i=0; i<N; i++)
        good &= can[i];
    cout << (good?"I become the guy.":"Oh, my keyboard!") << endl;
}