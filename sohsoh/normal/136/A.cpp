#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int p[101] = {0};
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        p[t - 1] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    return 0;
}