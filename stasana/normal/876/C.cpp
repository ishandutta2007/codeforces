#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <set>

using namespace std;

typedef long long ll;

int f(int x) {
    int n = x;
    while (n > 0) {
        x += n % 10;
        n /= 10;
    }
    return x;
}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = n; i > n - 1000; --i) {
        if (n == f(i)) {
            a.push_back(i);
        }
    }
    cout << a.size() << endl;
    for (int i = (int)a.size() - 1; i >= 0; --i) {
        cout << a[i] << endl;
    }
    return 0;
}