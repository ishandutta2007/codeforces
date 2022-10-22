#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    n %= 6;
    vector <int> data(3, 0);
    data[1] = 1;
    data[2] = 2;
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            swap(data[1], data[2]);
        } else {
            swap(data[0], data[1]);
        }
    }
    cout << data[m];
}
/*
1 2
0
1 1
1 1
*/