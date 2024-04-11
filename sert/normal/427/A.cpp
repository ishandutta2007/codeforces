#include <iostream>

using namespace std;

int n, s, h, a;

int main()
{
    cin >> n;
    while (n--) {
        cin >> h;
        s += h;
        if (s < 0) {
            a++;
            s = 0;
        }
    }

    cout << a;

    return 0;
}