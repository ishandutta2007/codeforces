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
        bool f = true, g = true;
        for(int i = 1; i < n; i++){
            if(s[i] == '1' && s[i - 1] == '1') f = false;
            if(s[i] == '0' && s[i - 1] == '0') g = f;
        }
        if(g) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}