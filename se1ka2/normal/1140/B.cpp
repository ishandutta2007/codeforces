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
        int ans = 10000000;
        for(int i = 0; i < n; i++){
            if(s[i] == '>'){
                ans = min(ans, i);
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '<'){
                ans = min(ans, n - 1 - i);
                break;
            }
        }
        cout << ans << endl;
    }
}