#include <bits/stdc++.h>
using namespace std;

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    setIO();
    int n;
    string s;
    cin>>s;
    n = s.length();
    cout << "3\n";
    cout << "L 2\n"; ++n;
    cout << "R 2\n"; n+=n-2;
    cout << "R " << (n-1) << "\n";
    return 0;
}