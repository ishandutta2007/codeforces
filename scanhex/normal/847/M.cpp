#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool ok = true;
    for (int i = 2; i < n; i++) {
        if (a[i] - a[i - 1] != a[1] - a[0]) {
            ok = false;
            break;
        }
    }

    if (ok) {
        cout << a[n - 1] + a[1] - a[0] << endl;
    } else {
        cout << a[n - 1] << endl;
    }

    return 0;
}