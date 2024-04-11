#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int ans = 10;
        for(int c = 0; c < 2; c++){
            string t = s;
            int a = 5, b = 5;
            int l = 0, r = 0;
            for(int i = 0; i < 10; i++){
                if((i + c) % 2){
                    if(s[i] != '0') l++;
                    a--;
                    if(l > b + r || r > a + l) ans = min(ans, i + 1);
                }
                else{
                    if(s[i] == '1') r++;
                    b--;
                    if(l > b + r || r > a + l) ans = min(ans, i + 1);
                }
            }
        }
        cout << ans << endl;
    }
}