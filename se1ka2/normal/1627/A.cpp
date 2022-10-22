#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m, r, c;
        cin >> n >> m >> r >> c;
        r--; c--;
        string s[52];
        for(int i = 0; i < n; i++) cin >> s[i];
        if(s[r][c] == 'B'){
            cout << 0 << endl;
            continue;
        }
        bool f = false;
        for(int i = 0; i < n; i++){
            if(s[i][c] == 'B') f = true;
        }
        for(int j = 0; j < m; j++){
            if(s[r][j] == 'B') f = true;
        }
        if(f){
            cout << 1 << endl;
            continue;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(s[i][j] == 'B') f = true;
            }
        }
        if(f) cout << 2 << endl;
        else cout << -1 << endl;
    }
}