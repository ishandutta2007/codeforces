#include <iostream>
using namespace std;

int N, K;

int main(){
    cin >> K >> N;

    cout << N * (6 * K - 1) << endl;
    for(int i=0; i<K; i++){
        cout << N * (1 + 6 * i) << " ";
        cout << N * (2 + 6 * i) << " ";
        cout << N * (3 + 6 * i) << " ";
        cout << N * (5 + 6 * i) << "\n";
    }

    cout.flush();
    return 0;
}