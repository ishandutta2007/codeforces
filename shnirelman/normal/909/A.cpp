#include <iostream>
#include <string>

using namespace std;

int main(){
    string s, s1;
    cin >> s >> s1;

    string ans = "";
    ans += s[0];
    for(int i = 1; i < s.length() && s[i] < s1[0]; i++){
        //cout << ans << endl;
        ans += s[i];
    }
    ans += s1[0];

    cout << ans;
}