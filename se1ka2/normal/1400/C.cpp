#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int x;
        cin >> x;
        string t;
        for(int i = 0; i < n; i++){
            if((i - x >= 0 && s[i - x] == '0') || (i + x < n && s[i + x] == '0')){
                t += '0';
            }
            else{
                t += '1';
            }
        }
        string u;
        for(int i = 0; i < n; i++){
            if((i - x >= 0 && t[i - x] == '1') || (i + x < n && t[i + x] == '1')){
                u += '1';
            }
            else{
                u += '0';
            }
        }
        if(u == s) cout << t << endl;
        else cout << -1 << endl;
    }
}