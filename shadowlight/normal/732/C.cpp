#include <bits/stdc++.h>

using namespace std;

int main() {
    vector <long long> data(3, 0);
    cin >> data[0] >> data[1] >> data[2];
    sort(data.begin(), data.end());
    long long N = data[2];
    if (data[1] < data[2]) {
        cout << 2 * N - 2 - data[0] - data[1];
    } else {
        if (data[0] < data[1]) {
            cout << N - 1 - data[0];
        } else {
            cout << 0 << endl;
        }
    }
}