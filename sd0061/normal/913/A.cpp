#include <bits/stdc++.h>
using namespace std;

int n , m;

int main() {

    cin >> n >> m;
    if (n <= 30) {
        cout << m % (1 << n) << endl;
    } else {
        cout << m << endl;
    }
}