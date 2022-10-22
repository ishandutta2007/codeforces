#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < n; i += 2){
        if(s[i] == s[i + 1]){
            if(s[i] == 'a') s[i] = 'b';
            else s[i] = 'a';
            ans++;
        }
    }
    cout << ans << endl;
    cout << s << endl;
}