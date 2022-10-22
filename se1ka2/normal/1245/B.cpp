#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int e = 0; e < t; e++){
        int n;
        cin >> n;
        int a, b, c;
        cin >> a >> b >> c;
        string s;
        cin >> s;
        char d[102];
        for(int i = 0; i < n; i++) d[i] = '?';
        for(int i = 0; i < n; i++){
            if(s[i] == 'R' && b > 0){
                d[i] = 'P';
                b--;
            }
            if(s[i] == 'P' && c > 0){
                d[i] = 'S';
                c--;
            }
            if(s[i] == 'S' && a > 0){
                d[i] = 'R';
                a--;
            }
        }
        if((a + b + c) * 2 > n){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
            if(d[i] == '?'){
                if(a > 0){
                    cout << 'R';
                    a--;
                }
                else if(b > 0){
                    cout << 'P';
                    b--;
                }
                else{
                    cout << 'S';
                    c--;
                }
            }
            else cout << d[i];
        }
        cout << endl;
    }
}