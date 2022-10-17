#include <iostream>
#define MOD 1000000007
using namespace std;

int N, K;
int way[2048][2048];

int main(){
    cin >> N >> K;
    int ans = 0;
    
    for(int v=1; v<=N; v++){
        way[1][v] = 1;
        if(K==1) ans = (ans + way[1][v]) % MOD;
    }

    for(int l=2; l<=K; l++)
        for(int v=1; v<=N; v++){
            for(int u=v; u<=N; u+=v)
                way[l][v] = (way[l][v] + way[l-1][u]) % MOD;
            if(l == K) ans = (ans + way[l][v]) % MOD;
        }

    cout << ans << endl;
}