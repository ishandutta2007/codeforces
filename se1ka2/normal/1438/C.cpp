#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int a[102][102];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) cin >> a[i][j];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((i + j) % 2 != a[i][j] % 2) a[i][j]++;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) cout << a[i][j] << " ";
            cout << endl;
        }
    }
}