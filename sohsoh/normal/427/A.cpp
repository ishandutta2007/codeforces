#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int policeN = 0, crimes = 0;

    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        if (e == -1) {
            if (policeN > 0) {
                policeN -= 1;
            } else {
                crimes += 1;
            }
        } else {
            policeN += e;
        }
    }

    cout << crimes << endl;
    return 0;
}