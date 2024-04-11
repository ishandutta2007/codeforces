#include <iostream>
using namespace std;

int N, M, K, v[1005];

int main(){
    cin >> N >> M >> K;

    for(int i=0; i<=M; i++)
        cin >> v[i];

    int a = 0;
    for(int i=0; i<M; i++)
        if(__builtin_popcount(v[i]^v[M]) <= K)
            a++;

    cout << a << endl;
    return 0;
}