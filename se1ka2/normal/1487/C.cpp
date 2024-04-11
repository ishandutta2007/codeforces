#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans[102][102];
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < i + (n + 1) / 2; j++) ans[i][j % n] = 1;
            for(int j = i - 1; j > i - (n + 1) / 2; j--) ans[i][(j + n) % n] = -1;
            if(n % 2 == 0) ans[i][(i + n / 2)] = 0;
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++) cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}