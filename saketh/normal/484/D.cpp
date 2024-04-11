#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long v[1000005];
long long b[1000005];

int main(){
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i=0; i<N; i++)
        cin >> v[i];

    b[0] = 0;
    b[1] = abs(v[1] - v[0]);

    for(int i=2; i<N; i++){
        if((v[i] < v[i-1]) ^ (v[i-1] < v[i-2]))
            b[i] = max(b[i-2] + abs(v[i] - v[i-1]), b[i-1]);

        else b[i] = b[i-1] + abs(v[i] - v[i-1]);
    }

    cout << b[N-1] << endl;
    return 0;
}