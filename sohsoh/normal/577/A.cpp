#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    long n, x;
    cin >> n >> x;

    long s = 0;

    for (long i = 1; i <= sqrt(x); i++) {
        if (x % i == 0 && x / i <= n && i <= n) {
            if (i * i == x) {
                s += 1;
            } else {
                s += 2;
            }
        }
    }

    cout << s << endl;
    return 0;
}