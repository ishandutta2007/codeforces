#include <iostream>

using namespace std;

int main() {
    long long n, m, k;
    cin >> n;
    if (n <= 2) {
        cout << -1;
        return 0;
    }
    long long st = 1;
    while (n % 2 == 0 && n != 4) {
        n /= 2;
        st *= 2;
    }
    if (n == 4) {
        m = 3;
        k = 5;
    } else {
        m = n * n / 2;
        k = m + 1;
    }
    m *= st;
    k *= st;
    cout << m << " " << k << endl;
}