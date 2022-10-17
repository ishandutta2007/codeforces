#include <iostream>
#define MOD 1000000007
using namespace std;

int T, K;
int way[100005], pre[100005];

int main(){
    cin >> T >> K;

    way[0] = 1;
    pre[0] = 1;

    for(int i=1; i<=100000; i++){
        way[i] = way[i-1];
        if(i >= K) way[i] = (way[i] + way[i-K]) % MOD;
        pre[i] = (pre[i-1] + way[i]) % MOD;
    }

    for(int a, b; T; T--){
        cin >> a >> b;
        cout << (pre[b] + MOD - pre[a-1]) % MOD << "\n";
    }

    cout.flush();
    return 0;
}