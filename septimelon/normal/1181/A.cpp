#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long x, y, z;
    cin >> x >> y >> z;
    long long s1 = x%z;
    long long s2 = y%z;
    if (s1 + s2 < z) {
        cout << x/z+y/z << " 0";
        return 0;
    }
    cout << x/z+y/z+1 << " ";
    cout << min(z-s1, z-s2);
    return 0;
}