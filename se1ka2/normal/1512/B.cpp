#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int x[2], y[2];
        int c = 0;
        string s[402];
        for(int i = 0; i < n; i++) cin >> s[i];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(s[i][j] == '*'){
                    x[c] = i;
                    y[c] = j;
                    c++;
                }
            }
        }
        if(x[0] == x[1]){
            if(x[0] == 0){
                s[1][y[0]] = '*';
                s[1][y[1]] = '*';
            }
            else{
                s[0][y[0]] = '*';
                s[0][y[1]] = '*';
            }
        }
        else if(y[0] == y[1]){
            if(y[0] == 0){
                s[x[0]][1] = '*';
                s[x[1]][1] = '*';
            }
            else{
                s[x[0]][0] = '*';
                s[x[1]][0] = '*';
            }
        }
        else{
            s[x[0]][y[1]] = '*';
            s[x[1]][y[0]] = '*';
        }
        for(int i = 0; i < n; i++) cout << s[i] << endl;
    }
}