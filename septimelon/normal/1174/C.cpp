#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[200000];
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
        a[i] = 0;
    int cura;
    cura = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] == 0) {
            cura++;
            a[i] = cura;
            for (int j = 2*i; j <= n; j+=i) {
                a[j] = cura;
            }
        }
    }
    for (int i = 2; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}