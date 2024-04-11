#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> a(n, 0);
    cin >> a[0];
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        cout << a[i] + a[i - 1] << " ";
    }
    cout << a[n - 1];
}