#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s[305];
        for(int i = 0; i < n; i++) cin >> s[i];
        int c[2][3]{0};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(s[i][j] == 'X') c[0][(i + j) % 3]++;
                if(s[i][j] == 'O') c[1][(i + j) % 3]++;
            }
        }
        int l = 0, r = 1;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(i == j) continue;
                if(c[0][i] + c[1][j] < c[0][l] + c[1][r]){
                    l = i;
                    r = j;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if((i + j) % 3 == l && s[i][j] == 'X') s[i][j] = 'O';
                if((i + j) % 3 == r && s[i][j] == 'O') s[i][j] = 'X';
            }
        }
        for(int i = 0; i < n; i++) cout << s[i] << endl;
    }
}