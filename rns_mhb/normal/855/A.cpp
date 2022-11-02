#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    set <string> S;
    while(n --) {
        string s;
        cin >> s;
        if(S.count(s)) cout << "YES" << endl;
        else cout << "NO" << endl;
        S.insert(s);
    }
}