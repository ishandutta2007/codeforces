#include <bits/stdc++.h>
using namespace std;

map<string, string> trans;

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        string s, t;
        cin >> s >> t;
        if(s.length() <= t.length())
            trans[s] = s;
        else
            trans[s] = t;
    }
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cout << trans[s] << " ";
    }
    cout << endl;
}