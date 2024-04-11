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
        int l;
        for(l = 1; l < n; l++){
            if(s[l] != s[l - 1]) break;
        }
        if(l == n){
            cout << (l + 2) / 3 << endl;
            continue;
        }
        s = s.substr(l) + s.substr(0, l) + '.';
        int c = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            c++;
            if(s[i] != s[i + 1]){
                ans += c / 3;
                c = 0;
            }
        }
        cout << ans << endl;
    }
}