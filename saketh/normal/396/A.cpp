#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long ll;

const int MAXN = 512;
const int MOD = 1000000007;

ll N, V, ncr[16000][512];
unordered_map<ll, int> fac;

void factor(ll arg){
    if(arg == 1) return;
    for(ll p=2; p*p <= arg; p++){
        if(arg%p) continue;
        while(arg%p == 0){
            fac[p]++;
            arg /= p;
        }
        factor(arg);
        return;
    }
    if(arg>1) fac[arg]++;
}

int main(){
    ncr[0][0] = 1;
    for(ll n=1; n<16000; n++){
        ncr[n][0] = 1;
        for(ll r=1; r<MAXN; r++)
            ncr[n][r] = (ncr[n-1][r] + ncr[n-1][r-1]) % MOD;
    }

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> V;
        factor(V);
    }

    ll ans = 1;
    for(pair<ll, int> kv : fac)
        ans = (ans * ncr[kv.second+N-1][N-1]) % MOD;
    cout << ans << endl;
    return 0;   
}