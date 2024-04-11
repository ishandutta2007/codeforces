#include <algorithm>
#include <iostream>
using namespace std;

int N, K;
int lo = 105, hi = -1;
int size[105];

int main(){
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> size[i];

        lo = min(lo, size[i]);
        hi = max(hi, size[i]);
    }

    if(hi - lo > K){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    for(int i=0; i<N; i++){
        for(int j=0; j<lo; j++)
            cout << K << " ";

        for(int j=lo; j<size[i]; j++)
            cout << j - lo + 1 << " ";

        cout << endl;
    }
}