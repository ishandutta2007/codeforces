#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int k = 1;
    int all = 0;
    int s = 0;

    while (all + k <= n) {
        n -= k;
        s++;
        if (k == 1)
            k = 2;
        else
            k = 1;
    }

    cout << s << endl;
    return 0;
}