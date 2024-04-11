#include <iostream>

using namespace std;

int ws(int n) {
    if (n % 10 == 0)
        n /= 10;
    else
        n--;

    return n;
}

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        n = ws(n);
    }

    cout << n << endl;
    return 0;
}