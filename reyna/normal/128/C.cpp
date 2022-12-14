#include <iostream>
using namespace std;
int C[2014][2014];
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 0; i < max(n,m);i++){
        C[i][i] = 1;
        C[0][i] = 1;
    }
    for(int i = 1;i < max(n,m);i++)
        for(int j = 1; j < i;j++)
            C[j][i] = (C[j-1][i-1] + C[j][i-1])%1000000007;
            
    
    cout << ((long long)C[2*k][n-1] * C[2*k][m-1])%1000000007;
}