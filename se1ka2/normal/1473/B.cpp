#include <iostream>
using namespace std;

bool div(string s, string t){
    int n = s.size(), m = t.size();
    if(n % m) return false;
    for(int i = 0; i < n; i += m){
        if(s.substr(i, m) != t) return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s, t;
        cin >> s >> t;
        string ans = "-1";
        for(int i = min((int)s.size(), (int)t.size()); i > 0; i--){
            if(div(s, s.substr(0, i)) && div(t, s.substr(0, i))){
                ans = "";
                for(int j = 0; j < (int)s.size() * (int)t.size() / i / i; j++) ans += s.substr(0, i);
                break;
            }
        }
        cout << ans << endl;
    }
}