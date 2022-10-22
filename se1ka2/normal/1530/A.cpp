#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        char ans = '1';
        for(int i = 0; i < (int)s.size(); i++){
            ans = max(ans, s[i]);
        }
        cout << ans << endl;
    }
}