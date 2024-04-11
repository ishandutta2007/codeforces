#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        bool e[102][102];
        for(int i = 0; i <= 100; i++){
            for(int j = 0; j <= 100; j++) e[i][j] = false;
        }
        for(int i = 0; i < n; i++){
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            e[b][c] = true;
        }
        bool f = false;
        for(int i = 0; i <= 100; i++){
            if(e[i][i]) f = true;
        }
        if(f && m % 2 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}