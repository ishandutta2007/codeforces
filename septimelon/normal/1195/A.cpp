#include <iostream>

using namespace std;

int main()
{
    int n, k;
    int a[2000];
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
        a[i] = 0;
    int inc;
    for (int i = 0; i < n; i++) {
        cin >> inc;
        a[inc]++;
    }
    int counec = 0;
    for (int i = 1; i <= k; i++) {
        if (a[i] % 2 == 1)
            counec++;
    }
    if (counec % 2 == 1)
        counec--;
    cout << n - counec/2 << endl;
    return 0;
}