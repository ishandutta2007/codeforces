#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[3][102];
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < n; j++) cin >> a[i][j];
        }
        int p[102];
        p[0] = a[0][0];
        for(int i = 0; i < n - 1; i++){
            if(a[0][i] != p[i - 1]) p[i] = a[0][i];
            else p[i] = a[1][i];
        }
        if(a[0][n - 1] != p[n - 2] && a[0][n - 1] != p[0]) p[n - 1] = a[0][n - 1];
        else if(a[1][n - 1] != p[n - 2] && a[1][n - 1] != p[0]) p[n - 1] = a[1][n - 1];
        else p[n - 1] = a[2][n - 1];
        for(int i = 0; i < n; i++) cout << p[i] << " ";
        cout << endl;
    }
}