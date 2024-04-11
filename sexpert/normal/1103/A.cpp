#include <bits/stdc++.h>
using namespace std;

int main() {
    bool vp = false, hp = false;
    string s;
    cin >> s;
    for(auto c : s) {
        if(c == '0') {
            if(vp)
                cout << "3 1\n";
            else
                cout << "1 1\n";
            if(vp)
                vp = false;
            else
                vp = true;
        }
        else {
            if(hp)
                cout << "4 1\n";
            else
                cout << "4 3\n";
            if(hp)
                hp = false;
            else
                hp = true;
        }
    }
}