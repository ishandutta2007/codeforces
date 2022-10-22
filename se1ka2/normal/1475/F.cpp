#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s[1002];
        for(int i = 0; i < n; i++) cin >> s[i];
        string t[1002];
        for(int i = 0; i < n; i++) cin >> t[i];
        bool b[1002][1002];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                b[i][j] = (s[i][j] == t[i][j]);
            }
        }
        bool f = true;
        for(int i = 1; i < n; i++){
            for(int j = 1; j < n; j++){
                if(b[i - 1][j - 1] ^ b[i - 1][j] ^ b[i][j - 1] ^ b[i][j]) f = false;
            }
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}