#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int r25 = 0, r50 = 0;

    bool possible = true;
    for (int i = 0; i < n; i++) {
        int paymentAmount;
        cin >> paymentAmount;

        if (paymentAmount == 25) {
            r25 += 1;
        } else if (paymentAmount == 50) {
            r50 += 1;
            if (r25 > 0) {
                r25 -= 1;
            } else {
                possible = false;
            }
        } else if (paymentAmount == 100) {
            if (r50 > 0 && r25 > 0) {
                r50 -= 1;
                r25 -= 1;
            } else if (r25 > 2) {
                r25 -= 3;
            } else {
                possible = false;
            }
        }
    }

    if (possible) {
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;
    return 0;
}