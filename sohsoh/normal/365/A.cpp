#include <iostream>

using namespace std;

int isGood(int n, int k) {
    int a[10] = {0};

    while (n > 0) {
        a[n % 10]++;

        n /= 10;
    }

    for (int i = 0; i <= k; i++) {
        if (a[i] <= 0) {
            return false;
        }
    }

    return true;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int s = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        if (isGood(t, k))
            s++;
    }

    cout << s << endl;
    return 0;
}