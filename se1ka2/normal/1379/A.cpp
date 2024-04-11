#include <iostream>
using namespace std;

string r = "abacaba";

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ans = "";
        for(int i = 0; i < n - 6; i++){
            if(s[i] == 'a' || s[i] == '?'){
                bool f = true;
                for(int j = i; j < i + 7; j++){
                    if(s[j] != r[j - i] && s[j] != '?'){
                        f = false;
                    }
                }
                if(f){
                    string u = s;
                    for(int j = i; j < i + 7; j++) u[j] = r[j - i];
                    int c = 0;
                    for(int j = 0; j < n - 6; j++){
                        if(u.substr(j, 7) == r) c++;
                    }
                    if(c == 1){
                        for(int j = 0; j < n; j++){
                            if(u[j] == '?') u[j] = 'z';
                        }
                        ans = u;
                        break;
                    }
                }
            }
        }
        if(ans != ""){
            cout << "YES" << endl;
            cout << ans << endl;
        }
        else cout << "NO" << endl;
    }
}