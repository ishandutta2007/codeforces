#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int ind0, indn;
    ind0 = 0;
    indn = 0;
    int cou = 0;
    int curab = 0;
    int curaa = 0;
    for (indn = 0; indn < b.size(); indn++) {
        if (a[indn] != b[indn]) curab++;
        if (indn > 0 && a[indn] != a[indn-1]) curaa++;
    }
    curab %= 2;
    curaa %= 2;
    if (curab == 0)
        cou++;
    while (indn < a.size()) {
        if (a[indn] != a[indn-1])
            curaa = 1 - curaa;
        if (ind0 > 0 && a[ind0] != a[ind0-1])
            curaa = 1 - curaa;
        if (curaa == 1)
            curab = 1 - curab;
        if (curab == 0) {
            //cout << indn << endl;
            cou++;
        }
        ind0++;
        indn++;
    }
    cout << cou << endl;
    return 0;
}