#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, i, k, p, s, m, l, xl, xxl;
    cin >> s >> p;
    if (s > p) p = s;
    p = 6 - p + 1;
    if (p == 6) cout << "1/1"; else
    if (p == 2) cout << "1/3"; else
    if (p == 3) cout << "1/2"; else
    if (p == 4) cout << "2/3"; else
    if (p == 1) cout << "1/6"; else
    if (p == 5) cout << "5/6";

}