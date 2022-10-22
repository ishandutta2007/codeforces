#include <iostream>

using namespace std;

int main()
{
    long long len;
    long long a, b, c;
    cin >> a >> b >> c;
    len = 2 * c + 2 * min(a, b);
    if (a != b) len++;
    cout << len << endl;
    return 0;
}