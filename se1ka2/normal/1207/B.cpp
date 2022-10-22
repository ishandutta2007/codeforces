#include <iostream>
using namespace std;

int a[52][52];
int b[52][52];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];
    int ans = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        if(a[i][j] == 1 && a[i + 1][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j + 1] == 1){
            b[i][j] = b[i + 1][j] = b[i][j + 1] = b[i + 1][j + 1] = 1;
            ans++;
        }
    }
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        if(a[i][j] != b[i][j]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        if(a[i][j] == 1 && a[i + 1][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j + 1] == 1)
            cout << i + 1 << " " << j + 1 << endl;
    }
}