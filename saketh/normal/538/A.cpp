#include <iostream>
using namespace std;

string t = "CODEFORCES";
string s;

int main(){
    cin >> s;

    bool ans = s == t;

    for(int i=0; i<s.length(); i++){
        for(int j=1; j<=(s.length()-i); j++){
            string c = s.substr(0, i) + s.substr(i+j);
            ans |= c == t;
        }
    }

    cout << (ans ? "YES" : "NO") << endl;
}