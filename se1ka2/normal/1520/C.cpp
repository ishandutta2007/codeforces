#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n == 2){
            cout << -1 << endl;
            continue;
        }
        int ans[102][102];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans[j][(i + j) % n] = i * n + j;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) cout << ans[i][j] + 1 << " ";
            cout << endl;
        }
    }
}