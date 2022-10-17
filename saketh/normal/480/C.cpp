#include <iostream>
#define MOD 1000000007
using namespace std;

int N, A, B, K;
int ways[5005][5005];
int pre[5005];

int main(){
    cin >> N >> A >> B >> K;
    
    if(A > B){
        A = N + 1 - A;
        B = N + 1 - B;
    }

    ways[0][A] = 1;
    pre[1] = ways[0][1];
    for(int f=2; f<B; f++)
        pre[f] = (ways[0][f] + pre[f-1]) % MOD;

    int ans = 0;

    for(int t=1; t<=K; t++){
        for(int f=1; f<B; f++){
            int diff = B - f;
            int up = (diff - 1)/2;
            
            ways[t][f] = pre[f+up];
            ways[t][f] = (ways[t][f] - ways[t-1][f]) % MOD;
            ways[t][f] = (ways[t][f] + MOD) % MOD;

            if(t == K) ans = (ans + ways[t][f]) % MOD;
        }

        pre[1] = ways[t][1];
        for(int f=2; f<B; f++)
            pre[f] = (ways[t][f] + pre[f-1]) % MOD;

    }

    cout << ans << endl;
    return 0;
}