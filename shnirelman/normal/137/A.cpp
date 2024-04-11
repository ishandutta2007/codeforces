#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string s;
    cin >> s;

    char c = s[0];
    int ans = 1;
    int cnt = 0;
    for(int i = 0; i < s.length(); i++){
        if(cnt == 5){
            ans++;
            cnt = 1;
            c = s[i];
        }
        else if(c == s[i]){
            cnt++;
        }
        else {
            ans++;
            c = s[i];
            cnt = 1;
        }
    }

    cout << ans;
}