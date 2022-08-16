#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

string s;

string solve() {
    int r = 0;
    bool eq = true;
    for (int i = 0; i + 1< s.length(); i++)
        if (s[i] != s[i+1]) eq = false;
    if (eq) return s;
    char a = s[0];
    char b = (a == '0' ? '1' : '0');
    string t = "";
    for (char c : s) {
        t = t + a + b;
    }
    return t;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>s;
        cout<<solve()<<"\n";
    }
    
    return 0;
}