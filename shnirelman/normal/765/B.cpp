#include <iostream>
#include <vector>

using namespace std;

int main(){
    string s;
    cin >> s;

    int a = 'a';
    bool ans = true;
    for(int i = 0; i < s.length(); i++){
        if(s[i] > a)ans = false;
        else if(s[i] == a)a++;
    }

    if(ans)cout << "YES";
    else cout << "NO";
}