#include <iostream>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;

    long long e = (n + 1) / 2;
    long long o = n / 2;

    if (k > e) {
        cout << (k - e) * 2 << endl;
    } else {
        cout << k * 2 - 1 << endl;
    }
    return 0;
}