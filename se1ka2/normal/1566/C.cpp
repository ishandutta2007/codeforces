#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        string s[2];
        cin >> n >> s[0] >> s[1];
        int ans = 0;
        bool b[100005];
        for(int i = 0; i < n; i++) b[i] = false;
        for(int i = 0; i < n; i++){
            if(s[0][i] != s[1][i]) ans += 2;
            if(s[0][i] == '0' && s[1][i] == '0'){
                ans++;
                if(i > 0 && !b[i - 1] && s[0][i - 1] == '1' && s[1][i - 1] == '1'){
                    b[i - 1] = true;
                    ans++;
                }
                else if(i < n - 1 && s[0][i + 1] == '1' && s[1][i + 1] == '1'){
                    b[i + 1] = true;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}