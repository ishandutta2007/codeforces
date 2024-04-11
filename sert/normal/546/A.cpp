#include <iostream>

using namespace std;

int main() {
    int n, k, w;
    cin >> k >> n >> w;
    cout << max(0, k * (w * (w + 1)) / 2 - n);
    return 0;
}