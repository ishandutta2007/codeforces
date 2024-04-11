#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while (true) {
        n += 1;
        int nt = n;

        int a[10] = {0};

        while(nt > 0) {
            a[nt % 10] += 1;
            nt /= 10;
        }

        int i;
        for (i = 0; i < 10; i++) {
            if (a[i] > 1) {
                break;
            }
        }

        if (i == 10) {
            cout << n << endl;
            break;
        }
    }
    return 0;
}