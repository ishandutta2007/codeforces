#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int s = 0;
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        for (int i = 0; i < 3; i++) {
            int t;
            cin >> t;

            if (t == 1)
                tmp++;
        }

        if (tmp > 1)
            s++;
    }

    cout << s << endl;
    return 0;
}