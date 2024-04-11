#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, s;
    cin >> a >> b >> s;
    int d = abs(a) + abs(b);
    if(d > s || d % 2 != s % 2)
        cout << "No\n";
    else
        cout << "Yes\n";
}