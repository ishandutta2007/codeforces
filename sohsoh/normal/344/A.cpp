#include <iostream>

using namespace std;

int main()
{
    int n, b = 0;
    cin >> n;

    int s = 0;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t != b) {
            s++;
            b = t;
        }
    }

    cout << s << endl;
    return 0;
}