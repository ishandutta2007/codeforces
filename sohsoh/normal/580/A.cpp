#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long prevN = -1;

    int l = 0, m = 1;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t >= prevN) {
            l++;
            m = max(l, m);
        } else {
            l = 1;
        }

        prevN = t;
    }

    cout << m << endl;
    return 0;
}