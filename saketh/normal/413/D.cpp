#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 2048;
const int MAXM = 1 << 12;
const int FIN = MAXM - 1; 

int N, K, MLIM;
int inp[MAXN];
ll ways[MAXN][MAXM];

int update(int mask, int val) {
    if(val == 4 && mask&1) return 2;
    mask += (val / 2);
    if(mask == MLIM) return FIN;
    return mask;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> K;
    
    for (int i = 0; i < N; i++) {
        cin >> inp[i];
    }

    MLIM = 1 << (K - 1);
    ways[0][0] = 1;

    for (int i = 0; i < N; i++) {
        if(inp[i] == 0 || inp[i] == 2){
            for (int m = 0; m < MLIM; m++) {
                int mm = update(m, 2);
                ways[i+1][mm] = (ways[i+1][mm] + ways[i][m]) % MOD;
            }
            ways[i+1][FIN] = (ways[i+1][FIN] + ways[i][FIN]) % MOD;
        }
        if(inp[i] == 0 || inp[i] == 4){
            for (int m = 0; m < MLIM; m++) {
                int mm = update(m, 4);
                ways[i+1][mm] = (ways[i+1][mm] + ways[i][m]) % MOD;
            }
            ways[i+1][FIN] = (ways[i+1][FIN] + ways[i][FIN]) % MOD;
        }
    }

    cout << ways[N][FIN] << endl;
}