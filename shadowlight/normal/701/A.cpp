#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> data(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> data[i];
        sum += data[i];
    }
    int cnt = 2 * sum / n;
    vector <bool> used(n, 0);
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        used[i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (used[j]) continue;
            if (data[i] + data[j] == cnt) {
                used[j] = 1;
                cout << i + 1 << " " << j + 1 << endl;
                break;
            }
        }
    }
}