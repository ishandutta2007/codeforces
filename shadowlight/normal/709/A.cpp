#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, b, d;
    cin >> n >> b >> d;
    int cnt = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > b) continue;
        sum += x;
        if (sum > d) {
            sum = 0;
            cnt++;
        }
    }
    cout << cnt;
}