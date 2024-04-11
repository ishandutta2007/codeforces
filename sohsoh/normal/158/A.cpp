#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int it = -1;
    int s = 0;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;

        if (t == 0)
            break;

        if (i == k)
            it = t;

        if (i <= k)
            s++;

        else if (t >= it)
            s++;
    }

    cout << s << endl;
    return 0;
}