#include <iostream>
#include <cmath>
using namespace std;

int V1, V2;
int T, D;

int main(){
    cin >> V1 >> V2 >> T >> D;

    int dist = V1;
    int S = V1;

    for(int t=1; t<T; t++){
        int M = V2 + D * (T-t-1);
        S = min(S+D, M);
        dist += S;
    }

    cout << dist << endl;
}