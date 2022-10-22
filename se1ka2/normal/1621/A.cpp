#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(k * 2 - 1 > n){
            cout << -1 << endl;
            continue;
        }
        char ans[42][42];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) ans[i][j] = '.';
        }
        for(int e = 0; e < k; e++) ans[e * 2][e * 2] = 'R';
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) cout << ans[i][j];
            cout << endl;
        }
    }
}