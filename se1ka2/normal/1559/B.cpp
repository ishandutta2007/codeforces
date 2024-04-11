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
        for(int i = 0; i < n; i++){
            if(s[i] == 'B'){
                if(i + 1 < n && s[i + 1] == '?') s[i + 1] = 'R';
            }
            if(s[i] == 'R'){
                if(i + 1 < n && s[i + 1] == '?') s[i + 1] = 'B';
            }
        }
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == 'B'){
                if(i - 1 >= 0 && s[i - 1] == '?') s[i - 1] = 'R';
            }
            if(s[i] == 'R'){
                if(i - 1 >= 0 && s[i - 1] == '?') s[i - 1] = 'B';
            }
        }
        if(s[0] == '?'){
            for(int i = 0; i < n; i++){
                if(i % 2) s[i] = 'B';
                else s[i] = 'R';
            }
        }
        cout << s << endl;
    }
}