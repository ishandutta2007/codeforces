#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        if(n == 1 || s[0] <= s[1]){
            cout << s[0] << s[0] << endl;
            continue;
        }
        int l;
        for(l = 1; l < n; l++){
            if(s[l] > s[l - 1]) break;
        }
        for(int i = 0; i < l; i++) cout << s[i];
        for(int i = l - 1; i >= 0; i--) cout << s[i];
        cout << endl;
    }
}