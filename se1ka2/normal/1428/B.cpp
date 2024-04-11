#include <iostream>
#include <string>
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
        bool l = false, r = false;
        for(int i = 0; i < n; i++){
            if(s[i] == '<') l = true;
            if(s[i] == '>') r = true;
        }
        if(!l || !r) cout << n << endl;
        else{
            int ans = 0;
            for(int i = 0; i < n; i++){
                if(s[i] == '-' || s[(i + n - 1) % n] == '-') ans++;
            }
            cout << ans << endl;
        }
    }
}