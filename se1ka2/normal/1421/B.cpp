#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s[202];
        for(int i = 0; i < n; i++) cin >> s[i];
        int b[202][202];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) b[i][j] = s[i][j] - '0';
        }
        if(b[0][1] + b[1][0] == 0){
            int c = b[n - 1][n - 2] + b[n - 2][n - 1];
            cout << 2 - c << endl;
            if(!b[n - 1][n - 2]) cout << n << " " << n - 1 << endl;
            if(!b[n - 2][n - 1]) cout << n - 1 << " " << n << endl;
        }
        else if(b[0][1] + b[1][0] == 2){
            int c = b[n - 1][n - 2] + b[n - 2][n - 1];
            cout << c << endl;
            if(b[n - 1][n - 2]) cout << n << " " << n - 1 << endl;
            if(b[n - 2][n - 1]) cout << n - 1 << " " << n << endl;
        }
        else{
            int c = b[n - 1][n - 2] + b[n - 2][n - 1];
            if(c >= 1){
                cout << 2 - c + 1 << endl;
                if(b[0][1]) cout << 1 << " " << 2 << endl;
                if(b[1][0]) cout << 2 << " " << 1 << endl;
                if(!b[n - 1][n - 2]) cout << n << " " << n - 1 << endl;
                if(!b[n - 2][n - 1]) cout << n - 1 << " " << n << endl;
            }
            else{
                cout << c + 1 << endl;
                if(!b[0][1]) cout << 1 << " " << 2 << endl;
                if(!b[1][0]) cout << 2 << " " << 1 << endl;
                if(b[n - 1][n - 2]) cout << n << " " << n - 1 << endl;
                if(b[n - 2][n - 1]) cout << n - 1 << " " << n << endl;
            }
        }
    }
}