#include <bits/stdc++.h>
using namespace std;

int main (void){
    int k, MOD;
    cin >> k >> MOD;
    int S[200005];
    memset(S, 0, sizeof S);
    int aux, aux2;
    for (int i=1; i<=k; i++){
        int j = i, m = 1;
        while (j>=1){
            aux = j%10;
            aux2 = int(log10(j)) + 1;
            S[aux2] += aux;
            S[aux2+m] += aux;
            m += 2;
            j /= 10;
        }
    }
    long long sum = 0;
    aux = int(log10(k)) + 1;
    for (int i=1; i<=2*aux; i++){
        sum=(sum + (long long)(S[i]*pow(10, i - 1))) % MOD;
    }
    cout<< sum << "\n";
    return 0;
}