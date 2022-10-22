#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int s[6] = {a + b + c, a + b * c, a * b + c, a * b * c, a * (b + c), (a + b) * c};
    int m = 0;

    for (int i = 0; i < 6; i++) {
        if (s[i] > m)
            m = s[i];
    }

    cout << m << endl;
    return 0;
}