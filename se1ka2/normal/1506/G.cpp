#include <iostream>
using namespace std;

bool b[200005][26][26];

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int a[200005];
        for(int i = 0; i < n; i++) a[i] = s[i] - 'a';
        for(int i = 0; i <= n; i++){
            for(int j = 0; j < 26; j++){
                for(int k = 0; k < 26; k++) b[i][j][k] = 0;
            }
        }
        for(int j = 0; j < 26; j++){
            bool c[26]{0};
            for(int i = n - 1; i >= 0; i--){
                for(int k = 0; k < 26; k++) b[i][j][k] = b[i + 1][j][k];
                c[a[i]] = true;
                if(a[i] == j){
                    for(int k = 0; k < 26; k++) b[i][j][k] = c[k];
                }
            }
        }
        bool c[26]{0};
        for(int j = 0; j < 26; j++){
            if(!b[0][j][j]) c[j] = true;
        }
        for(int i = 0; i < n; i++){
            if(c[a[i]]) continue;
            bool f = true;
            for(int j = a[i] + 1; j < 26; j++){
                if(c[j]) continue;
                bool g = true;
                for(int k = 0; k < 26; k++){
                    if(!c[k] && !b[i][j][k]){
                        g = false;
                        break;
                    }
                }
                if(g){
                    f = false;
                    break;
                }
            }
            if(f){
                cout << s[i];
                c[a[i]] = true;
            }
        }
        cout << endl;
    }
}