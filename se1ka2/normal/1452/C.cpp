#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int ans = 0, x = 0, y = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                x++;
            }
            if(s[i] == ')'){
                if(x){
                    ans++;
                    x--;
                }
            }
            if(s[i] == '['){
                y++;
            }
            if(s[i] == ']'){
                if(y){
                    ans++;
                    y--;
                }
            }
        }
        cout << ans << endl;
    }
}