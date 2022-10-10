#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y, z, t1, t2, t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    int tstairs = t1*abs(x - y);
    int telev = t2*abs(x - z) + t3 + t3 + t2*abs(x - y) + t3;
    if(telev <= tstairs)
        cout << "YES\n";
    else
        cout << "NO\n";
}