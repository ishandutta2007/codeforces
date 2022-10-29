#include <iostream>

using namespace std;

int
main()
{
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        if (k == 0) {
            cout << "1\n";
        } else {
            cout << "-1\n";
        }
    } else {
        int num_par = n / 2;
        if (k < num_par) {
            cout << "-1\n";
        } else {
            int first_num = k - num_par + 1;
            cout << first_num << " " << (2 * first_num);
            for (int i = 3, j = 2 * first_num + 1; i <= n; ++i, ++j) {
                cout << " " << j;
            }
            cout << "\n";
        }
    }
    return 0;
}