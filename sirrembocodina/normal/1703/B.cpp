#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        string a;
        cin >> a;
        int sum = 0;
        vector<int> was(26);
        for (int j = 0; j < n; j++) {
            if (was[a[j] - 'A']) {
                sum++;
            } else {
                sum += 2;
            }
            was[a[j] - 'A'] = true;
        }
        cout << sum << '\n';
    }
}