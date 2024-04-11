#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

long long a[6];

int main() {
    ///freopen("a.in", "r", stdin);
    for (int i = 0; i < 6; i++)
        cin >> a[i];
    sort(a, a + 6);
    if ((a[0] == a[3] && a[4] == a[5]) || (a[0] == a[1] && a[2] == a[5]))
        cout << "Elephant\n";
    else if (a[0] < a[3] && a[1] < a[4] && a[2] < a[5])
        cout << "Alien\n";
    else cout << "Bear\n";
    return 0;
}