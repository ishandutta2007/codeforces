#include <iostream>
using namespace std;

int N, X, K;
int seen[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> X >> K;
        if(seen[K-1] < X){ cout << "NO" << endl; return 0; }
        if(seen[K-1] == X) seen[K-1]++;
    }

    cout << "YES" << endl;
    return 0;
}