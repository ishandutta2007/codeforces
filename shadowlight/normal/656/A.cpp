#include <iostream>
#include <math.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    if (n >= 13) cout << (long long) pow(2, n) - 100 * (long long) pow(2, n - 13); else cout << (long long) pow(2,n);
}