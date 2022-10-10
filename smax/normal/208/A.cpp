#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s, ret = "";
    cin >> s;
    for (char c : s) {
        ret += c;
        if (ret.length() >= 3 && ret.substr(ret.length()-3) == "WUB")
            ret = ret.substr(0, ret.length()-3) + " ";
    }
    ret = ret.substr(ret.find_first_not_of(" "));
    cout << ret.substr(0, ret.find_last_not_of(" ") + 1) << endl;
    
    return 0;
}