#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        if (m >= i)
            m -= i;
        else
            break;

        if (i >= n)
            i = 0;
    }

    cout << m << endl;
    return 0;
}