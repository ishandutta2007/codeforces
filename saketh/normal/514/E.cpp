#include <cstdlib>
#include <iostream>
#include <string.h>
using namespace std;

typedef int ll;
const int MOD = 1000000007;
const int ST = 101;

ll tmp[ST][ST];

void mult(ll a[ST][ST], ll b[ST][ST]){
    for(int i=0; i<ST; i++)
        for(int j=0; j<ST; j++){
            tmp[i][j] = 0;
            for(int k=0; k<ST; k++){
                tmp[i][j] += (a[i][k] * 1LL * b[k][j]) % MOD;
                if(tmp[i][j] >= MOD) tmp[i][j] -= MOD;
            }
        }
    memcpy(a, tmp, sizeof(tmp));
}

ll trans[ST][ST];
ll res[ST][ST];

int N, X;
int ct[ST];

void build(){
    for(int i=0; i<ST; i++)
        res[i][i] = 1;

    for(int i=0; i<ST-1; i++)
        trans[i][i+1] = 1;    

    trans[ST-1][ST-1] = 1;

    for(int e=1; e<=ST-1; e++){
        trans[ST-1][ST-e] = (trans[ST-1][ST-e] + ct[e]) % MOD;
        trans[ST-1][ST-e-1] = (trans[ST-1][ST-e-1] - ct[e] + MOD) % MOD;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> X;

    for(int i=0; i<N; i++){
        int V;
        cin >> V;
        ct[V]++;
    }

    build();
        
    while(X){
        if(X%2) mult(res, trans);
        mult(trans, trans);
        X/=2;
    }

    cout << res[ST-1][ST-1] << endl;
}