#include <iostream>

using namespace std;

int main()
{
    long n;
    cin >> n;

    long long s = 0;
    long long sn = 0;
    long long a = 9;
    int b = 1;
    while (sn + a <= n) {
        sn += a;
        s += b * a;
        b += 1;
        a *= 10;
    }

    long long remainNums = n - sn;
    s += remainNums * b;

    cout << s << endl;
    return 0;
}