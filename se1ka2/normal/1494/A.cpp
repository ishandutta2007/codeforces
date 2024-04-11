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
        int c[3]{0};
        for(int i = 0; i < n; i++){
            c[s[i] - 'A']++;
        }
        if(s[0] == s[n - 1]){
            cout << "NO" << endl;
            continue;
        }
        int d = c[s[0] - 'A'] - c[s[n - 1] - 'A'];
        char e[3];
        bool f = true;
        for(int i = 0; i < 3; i++){
            if(s[0] == 'A' + i) e[i] = '(';
            else if(s[n - 1] == 'A' + i) e[i] = ')';
            else{
                if(d == c[i]) e[i] = ')';
                else if(d == -c[i]) e[i] = '(';
                else f = false;
            }
        }
        if(!f){
            cout << "NO" << endl;
            continue;
        }
        int h = 0;
        for(int i = 0; i < n; i++){
            if(e[s[i] - 'A'] == '(') h++;
            else h--;
            if(h < 0) f = false;
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}