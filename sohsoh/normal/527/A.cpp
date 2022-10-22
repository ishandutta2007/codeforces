#include <iostream>

using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;

    long long s = 0;
    while (true) {
        if (a > b) {
            s += (a / b);
            a -= (a / b) * b;
        } else {
            s += (b / a);
            b -= (b / a) * a;
        }

        if (a == 0 || b == 0) {
            break;
        }
    }

    cout << s << endl;
    return 0;
}