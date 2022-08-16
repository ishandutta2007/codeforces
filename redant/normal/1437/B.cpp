#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, t;
    for (cin >> t; t--; ) {
        string s;
        cin >> n >> s;
        cout<< (n - (unique(s.begin(), s.end()) - s.begin()) + 1) / 2 << "\n";
    }    
    return 0;
}