#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s[52];
        for(int i = 0; i < n; i++) cin >> s[i];
        string t[52];
        for(int i = 0; i < n; i++) t[i] = s[i];
        bool f = true;
        for(int c = 0; c < 2; c++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if((i + j + c) % 2) t[i][j] = 'R';
                    else t[i][j] = 'W';
                }
            }
            f = true;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(s[i][j] != '.' && t[i][j] != '.' && s[i][j] != t[i][j]) f = false;
                }
            }
            if(f) break;
        }
        if(f){
            cout << "YES" << endl;
            for(int i = 0; i < n; i++) cout << t[i] << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}