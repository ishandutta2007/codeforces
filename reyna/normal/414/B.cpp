#include <iostream>
using namespace std;
long long arr[2001][2001];
int main(){
    int n,k;
    cin >> n
     >> k;
    for(int i = 1; i <= n;i++){
        arr[0][i] = 1;
    }
    for(int i = 1;i <= k;i++){
        for(int j = 1; j <= n;j++){
            for(int l = 1; l*j <= n;l++){
                arr[i][l*j]+=arr[i-1][j];
                arr[i][l*j]%=1000000007;
            }
        }
    }
    long long counter = 0;
    for(int i = 1; i <= n;i++){
        counter+=arr[k-1][i];
        counter%=1000000007;
    }
    cout << counter << endl;
    return 0;
}