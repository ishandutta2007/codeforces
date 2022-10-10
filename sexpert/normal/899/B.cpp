#include <bits/stdc++.h>
using namespace std;

int main() {
    string mo = "dadcdcddcdcddadcdcddcdcddbdcdcddcdcddadcdcddcdcddadcdcddcdcddadcdcddcdcd", ot = "";
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ot += 'a' + x - 28;
    }
    for(int i = 0; i < mo.length(); i++) {
        if(mo.substr(i, n) == ot) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}