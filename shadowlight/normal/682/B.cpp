#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> data(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    sort(data.begin(), data.end());
    int now = 1;
    for (int i = 0; i < n; i++) {
        if (data[i] >= now) {
            now++;
        }
    }
    cout << now;
}