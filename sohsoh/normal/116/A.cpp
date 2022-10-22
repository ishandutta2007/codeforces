#include <iostream>

using namespace std;

int main()
{
    int n, m = 0, p = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        p -= a;
        p += b;

        m = max(p, m);
    }

    cout << m << endl;
    return 0;
}