#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        string a, b;
        int c = 0, d = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                if(i == n - 1 || (c == 2 && d == 2) || c == 3){
                    c--; d--;
                    a += ')';
                    b += ')';
                }
                else{
                    c++; d++;
                    a += '(';
                    b += '(';
                }
            }
            else{
                if(c == 0){
                    c = -1;
                    break;
                }
                if(c == d){
                    c++; d--;
                    a += '(';
                    b += ')';
                }
                else{
                    c--; d++;
                    a += ')';
                    b += '(';
                }
            }
        }
        if(c == 0 && d == 0){
            cout << "YES" << endl;
            cout << a << endl;
            cout << b << endl;
        }
        else cout << "NO" << endl;
    }
}