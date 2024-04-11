#include <iostream>

using namespace std;

int main()
{
    int s = 0, o = 0, e = 0;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if (tmp % 2 == 0)
            e++;
        else
            o++;

        s += tmp;
    }

    if (s % 2 == 0)
        cout << e;
    else
        cout << o;
    return 0;
}