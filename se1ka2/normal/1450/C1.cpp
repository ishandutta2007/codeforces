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
        int c[3]{0};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(s[i][j] == 'X') c[(i + j) % 3]++;
            }
        }
        int l = 0;
        for(int i = 1; i < 3; i++){
            if(c[i] < c[l]) l = i;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if((i + j) % 3 == l && s[i][j] == 'X') s[i][j] = 'O';
            }
        }
        for(int i = 0; i < n; i++) cout << s[i] << endl;
    }
}