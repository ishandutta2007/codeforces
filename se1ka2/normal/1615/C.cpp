#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int c = 0, d = 0;
        for(int i = 0; i < n; i++) c += s[i] - '0';
        for(int i = 0; i < n; i++) d += t[i] - '0';
        int ans = -1;
        if(c == d){
            int e = 0;
            for(int i = 0; i < n; i++){
                if(s[i] != t[i]) e++;
            }
            if(ans == -1 || ans > e) ans = e;
        }
        if(c + d == n + 1){
            int e = 0;
            for(int i = 0; i < n; i++){
                if(s[i] == t[i]) e++;
            }
            if(ans == -1 || ans > e) ans = e;
        }
        cout << ans << endl;
    }
}