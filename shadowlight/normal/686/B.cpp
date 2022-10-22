#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n, x;
    cin >> n;
    vector <int> data(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (data[j - 1] > data[j]) {
                swap(data[j - 1], data[j]);
                cout << j << " " << j + 1 << endl;
            }
        }
    }
}