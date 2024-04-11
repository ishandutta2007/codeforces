#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    string s;

    cin >> s;

    bool b1 = false, b2 = false;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            cout << b1;
            b1 = !b1;
        }
        else{
            cout << b2;
            b2 = !b2;
        }
    }
    cout << "\n";

    return 0;
}