#include <iostream>
using namespace std;

long long N, M, K;

int main(){
    cin >> N >> M >> K;

    if(N-1 + M-1 < K){
        cout << -1 << endl;
        return 0;
    } 

    long long ans = 0;

    //max vert
    if(K >= M-1){
        long long hori = K - (M-1);
        long long rows = N / (hori + 1);
        ans = max(ans, rows);
    }
    else ans = max(ans, N * (M/(K+1)));

    swap(N, M);

    //max horiz
    if(K >= M-1){
        long long hori = K - (M-1);
        long long rows = N / (hori + 1);
        ans = max(ans, rows);
    }
    else ans = max(ans, N * (M/(K+1)));

    cout << ans << endl;
    return 0;
}