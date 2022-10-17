#include <iostream>
using namespace std;

int N, X, Y, A;
bool occ[128];

int main(){
    cin >> N >> X >> Y;
    for(int i=1; i<N; i++){
        int L, R;
        cin >> L >> R;
        for(int j=L; j<R; j++)
            occ[j] = true;
    }

    for(int j=X; j<Y; j++)
        A += !occ[j];
    cout << A << endl;
}