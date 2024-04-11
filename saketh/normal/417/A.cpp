#include <iostream>
using namespace std;

int C, D, N, M, K;
int ans = 0x7fffffff;

int main(){
    cin >> C >> D >> N >> M >> K;
    for(int m=0; m<=M; m++){
        int cost = m * C;
        cost += D * max(0, N*(M-m) - K);
        ans = min(ans, cost);
    }
    cout << ans << endl;
    return 0;
}