#include <iostream>
using namespace std;

int N, M, A, B;

int main(){
    cin >> N >> M >> A >> B;

    int ans = A * N;
    ans = min(ans, B * (N / M) + A * (N % M));
    ans = min(ans, B * ((N + M - 1) / M));

    cout << ans << endl;
    return 0;
}