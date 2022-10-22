#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int ans = 10000000;
        for(int i = 0; i <= n; i++){
            int r = 0;
            for(int j = 0; j < i; j++){
                if(s[j] == '1') r++;
            }
            for(int j = i; j < n; j++){
                if(s[j] == '0') r++;
            }
            ans = min(ans, r);
            r = 0;
            for(int j = 0; j < i; j++){
                if(s[j] == '0') r++;
            }
            for(int j = i; j < n; j++){
                if(s[j] == '1') r++;
            }
            ans = min(ans, r);
        }
        cout << ans << endl;
    }
}