#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, r;
    cin >> a >> b >> r;

    cout << (a < r * 2 || b < r * 2 ? "Second" : "First") << endl;
}