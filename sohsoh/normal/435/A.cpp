#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int bus = 1;
    int busCap = m;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if (busCap - tmp >= 0) {
            busCap -= tmp;

            if (i == n - 1) {
                break;
            }
        } else {
            bus += 1;
            busCap = m - tmp;
        }
    }

    cout << bus;
    return 0;
}