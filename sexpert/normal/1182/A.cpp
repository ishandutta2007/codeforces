#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n % 2)
        cout <<"0\n";
    else
        cout << (1 << (n/2)) << '\n';
}