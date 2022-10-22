#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string s;
    cin >> s;

    s += 'n';

    vector<bool> b(256, false);
    b[int('a')] = b[int('e')] = b[int('i')] =
    b[int('o')] = b[int('u')] = b[int('n')] = true;

    int ans = true;
    for(int i = 0; i < s.length() - 1; i++){
        if(!b[int(s[i])] && (!b[int(s[i + 1])] || s[i + 1] == 'n'))ans = false;
    }

    cout << (ans ? "YES" : "NO");
}