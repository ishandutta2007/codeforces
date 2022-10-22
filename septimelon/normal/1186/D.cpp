#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    double a;
    double suma = 0.;
    long long b;
    long long sumb1 = 0;
    long long sumb2 = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        suma += a;
        sumb2 = suma;
        if (abs(suma-(double)sumb2) > 0.5) {
            sumb2++;
            if (abs(suma-(double)sumb2) > 0.5)
                sumb2 -= 2;
        }
        b = sumb2 - sumb1;
        sumb1 = sumb2;
        cout << b << endl;
    }
    return 0;
}