#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        string s;
        cin >> s;
        int n = s.size();
        bool f[26];
        fill(f, f + 26, false);
        for(int i = 0; i < n; i++){
            if(i == n - 1){
                f[s[i] - 'a'] = true;
                continue;
            }
            if(s[i] != s[i + 1]) f[s[i] - 'a'] = true;
            else i++;
        }
        for(int i = 0; i < 26; i++){
            char ch = 'a' + i;
            if(f[i]) cout << ch;
        }
        cout << endl;
    }
}