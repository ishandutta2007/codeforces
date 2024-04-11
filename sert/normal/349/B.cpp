#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

typedef int ll;

const ll N = 2014;

int kol, ost, n, a[N], uk = 9, v, mn;

int main() {

    //freopen("a.in", "r", stdin);

    ///Test: #33, : 0 ., : 0 ,  : 0,   : 0, : CRASHED

    cin >> v;
    for (int i = 1; i <= 9; i++)
        cin >> a[i];
    mn = 9;
    for (int i = 8; i >= 1; i--)
        if (a[i] < a[mn])
            mn = i;
    kol = v / a[mn];
    ost = v % a[mn];

    if (a[mn] > v) {
        cout << "-1";
        return 0;
    }

    while (ost > 0) {
        while (a[uk] - a[mn] > ost) {
            uk--;
            if (uk == mn)
                break;
        }
        if (uk == mn)
            break;
        ost -= (a[uk] - a[mn]);
        printf("%d", uk);
        kol--;
        if (kol == 0)
            break;
    }
    for (int i = 0; i < kol; i++)
        printf("%d", mn);

    return 0;
}