#include <iostream>

using namespace std;

int absa(int n) {
    if (n < 0)
        n *= -1;

    return n;
}

int main()
{
    int a, b;
    cin >> a >> b;

    int aWins = 0, bWins = 0, draws = 0;

    for (int i = 1; i <= 6; i++) {
        if (absa(a - i) < absa(b - i)) {
            aWins += 1;
        } else if (abs(a - i) == abs(b - i)) {
            draws += 1;
        } else {
            bWins += 1;
        }
    }

    cout << aWins << " " << draws << " " << bWins << endl;
    return 0;
}