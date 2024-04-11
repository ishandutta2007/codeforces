#include <bits/stdc++.h>

using namespace std;

vector <int> str;

bool fl = 0;

int main() {
    int x, y, n;
    cin >> x >> y >> n;
    n--;
    int a = n / (2 * y);
    int k = n - a * (2 * y);
    k /= 2;
    cout << a + 1 << " " << k + 1 << " ";
    if (n % 2) {
        cout << "R";
    } else {
        cout << "L";
    }
}