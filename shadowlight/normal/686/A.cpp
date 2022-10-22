#include <iostream>

using namespace std;

int main() {
    long long n, x;
    cin >> n >> x;
    long long cnt = 0;
    for (long long i = 0; i < n; i++) {
        char c;
        long long d;
        cin >> c >> d;
        if (c == '+') {
            x += d;
        } else {
            if (x >= d) {
                x -= d;
            } else {
                cnt++;
            }
        }
    }
    cout << x << " " << cnt << endl;
}