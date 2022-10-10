#include <bits/stdc++.h>
using namespace std;

int a[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int v;
    cin >> v;
    for (int i=1; i<=9; i++)
        cin >> a[i];

    int minCost = *min_element(a + 1, a + 10), numDigits = v / minCost;
    if (numDigits == 0)
        cout << "-1\n";
    else {
        while (numDigits--)
            for (int i=9; i>0; i--)
                if (numDigits * minCost <= v - a[i]) {
                    cout << i;
                    v -= a[i];
                    break;
                }
        cout << "\n";
    }

    return 0;
}