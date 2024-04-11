#include <iostream>
#include <string>
using namespace std;

const int K = 100;

int main()
{
    int t;
    cin >> t;
    for(int w = 0; w < t; w++){
        string s;
        cin >> s;
        char c[200];
        int d[26];
        fill(d, d + 26, -1);
        fill(c, c + 200, '.');
        c[K] = s[0];
        d[s[0] - 'a'] = K;
        int e = K;
        bool f = true;
        int n = s.size();
        for(int i = 1; i < n; i++){
            if(d[s[i] - 'a'] == -1){
                if(c[e + 1] == '.'){
                    c[e + 1] = s[i];
                    d[s[i] - 'a'] = e + 1;
                    e++;
                }
                else if(c[e - 1] == '.'){
                    c[e - 1] = s[i];
                    d[s[i] - 'a'] = e - 1;
                    e--;
                }
                else{
                    f = false;
                    break;
                }
            }
            else{
                if(abs(d[s[i] - 'a'] - e) >= 2){
                    f = false;
                    break;
                }
                e = d[s[i] - 'a'];
            }
        }
        if(!f){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        int l = 0;
        for(int i = 0; i < 26; i++){
            l = max(l, d[i]);
        }
        char ans[26];
        fill(ans, ans + 26, '.');
        for(int i = 0; i < 26; i++){
            if(d[i] != -1) ans[l - d[i]] = char('a' + i);
        }
        for(int i = 0; i < 26; i++) if(ans[i] != '.') cout << ans[i];
        for(int i = 0; i < 26; i++) if(d[i] == -1) cout << char('a' + i);
        cout << endl;
    }
}