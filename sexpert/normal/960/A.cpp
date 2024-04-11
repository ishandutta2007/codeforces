#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int cta = 0, ctb = 0, ctc = 0;
    if(s[0] != 'a') {
        cout << "NO\n";
        return 0;
    }
    while(s[0] == 'a') {
        cta++;
        s = s.substr(1);
    }
    if(s.empty() || s[0] != 'b') {
        cout << "NO\n";
        return 0;
    }
    while(s[0] == 'b'){
        ctb++;
        s = s.substr(1);
    }
    if(s.empty() || s[0] != 'c') {
        cout << "NO\n";
        return 0;
    }
    while(s[0] == 'c') {
        ctc++;
        s = s.substr(1);
    }
    if(!s.empty() || (ctc != cta && ctc != ctb)) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
}