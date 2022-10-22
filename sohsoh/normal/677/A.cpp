#include <iostream>

using namespace std;

int main()
{
    int n, h;
    cin >> n >> h;

    int k = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        if (t > h)
            k++;
    }

    cout << (n - k) + k * 2 << endl;
    return 0;
}