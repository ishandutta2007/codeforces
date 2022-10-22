#include <iostream>

using namespace std;

int main()
{
    int open = 0, close = 0, n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;

        if (c == '0')
            open++;
        else
            close++;
    }

    if (n == 1) {
        if (close == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    } else {
        if (open == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}