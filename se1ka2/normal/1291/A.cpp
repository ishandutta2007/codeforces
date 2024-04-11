#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans[2];
        ans[0] = ans[1] = -1;
        for(int i = 0; i < n; i++){
            if((s[i] - '0') % 2){
                if(ans[0] == -1) ans[0] = s[i] - '0';
                else ans[1] = s[i] - '0';
            }
        }
        if(ans[1] == -1) cout << -1 << endl;
        else cout << ans[0] << ans[1] << endl;
    }
}