#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int n = a + b;
        string s;
        cin >> s;
        int c[2]{0};
        bool f = true;
        for(int i = 0; i < n; i++){
            if(s[i] == '?') continue;
            c[s[i] - '0']++;
            if(s[n - i - 1] != '?' && s[i] != s[n - i - 1]) f = false;
        }
        for(int i = 0; i < n; i++){
            if(s[i] == '?'){
                if(s[n - i - 1] == '?') continue;
                s[i] = s[n - i - 1];
                c[s[i] - '0']++;
            }
        }
        if(c[0] > a || c[1] > b) f = false;
        for(int i = 0; i < n / 2; i++){
            if(s[i] == '?'){
                if(a - c[0] >= 2){
                    s[i] = s[n - i - 1] = '0';
                    c[0] += 2;
                }
                else if(b - c[1] >= 2){
                    s[i] = s[n - i - 1] = '1';
                    c[1] += 2;
                }
                else f = false;
            }
        }
        if(n % 2 && s[n / 2] == '?'){
            if(a - c[0]){
                c[0]++;
                s[n / 2] = '0';
            }
            else{
                c[1]++;
                s[n / 2] = '1';
            }
        }
        if(a - c[0] || b - c[1]) f = false;
        if(!f) cout << -1 << endl;
        else cout << s << endl;
    }
}