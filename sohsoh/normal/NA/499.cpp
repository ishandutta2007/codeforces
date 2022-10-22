#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;

        if (t.size() > 10) {
            cout << t[0] << t.size() - 2 << t[t.size() - 1] << endl;
        } else {
            cout << t << endl;
        }
    }
    return 0;
}