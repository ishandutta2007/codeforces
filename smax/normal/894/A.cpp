#include <bits/stdc++.h>
using namespace std;

int main() {
    int ret = 0, a[100];
    vector<int> q;
    string s;
    cin >> s;
    a[0] = s[0] == 'A' ? 1 : 0;
    if (s[0] == 'Q')
        q.push_back(0);
    for (int i=1; i<s.length(); i++) {
        if (s[i] == 'A')
            a[i] = a[i-1] + 1;
        else
            a[i] = a[i-1];
        if (s[i] == 'Q') {
            for (int j : q)
                ret += a[i] - a[j];
            q.push_back(i);
        }
    }
    cout << ret << endl;
    
    return 0;
}