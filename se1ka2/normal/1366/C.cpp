#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int a[35][35];
        int c[100][2];
        for(int i = 0; i < 100; i++) c[i][0] = c[i][1] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
                c[i + j][a[i][j]]++;
            }
        }
        int ans = 0;
        for(int i = 0; i < (n + m - 1) / 2; i++){
            ans += min(c[i][0] + c[n + m - 2 - i][0], c[i][1] + c[n + m - 2 - i][1]);
        }
        cout << ans << endl;
    }
}