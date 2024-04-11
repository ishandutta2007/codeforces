#include <iostream>
using namespace std;

int K, N, W;

int main(){
    cin >> K >> N >> W;
    cout << max(0, (K + W * K) * W / 2 - N) << endl;
}