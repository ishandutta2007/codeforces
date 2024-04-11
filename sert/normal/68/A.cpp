#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a, b, p1, p2, p3, p4, m;
    cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
    m = p1;
    m = min(m, p2);
    m = min(m, p4);
    m = min(m, p3);
    m = min(m, b + 1);
    if (m <= a)
      cout << 0;
    else
      cout << m - a;
    return 0;
}