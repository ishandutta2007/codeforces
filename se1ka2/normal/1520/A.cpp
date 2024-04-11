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
        bool b[26]{0};
        bool f = true;
        for(int i = 0; i < n; i++){
            if(b[s[i] - 'A'] && s[i] != s[i - 1]){
                f = false;
                break;
            }
            b[s[i] - 'A'] = true;
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}