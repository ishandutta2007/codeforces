#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        bool p = true;
        int c = 0;
        int d = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                c++;
                if(s[i] != s[n - i - 1]){
                    p = false;
                    d++;
                }
            }
        }
        if(p){
            if(c == 1) cout << "BOB" << endl;
            else if(c % 2) cout << "ALICE" << endl;
            else cout << "BOB" << endl;
        }
        else if(d == 1 && c == 2) cout << "DRAW" << endl;
        else cout << "ALICE" << endl;
    }
}