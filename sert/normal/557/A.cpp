#include <bits/stdc++.h>

#define ff first
#define ss second
#define sl (l1 + l2 + l3)
#define sr (r1 + r2 + r3)

using namespace std;

typedef long long ll;

ll n, x, k;
ll l1, l2, l3, r1, r2, r3;

void fail() {
    cout << "No";
    exit(0);
}

int main() {
    //freopen("a.in", "r", stdin);

    cin >> n;
    cin >> l1 >> r1;
    cin >> l2 >> r2;
    cin >> l3 >> r3;
    while (sr > sl) {
        while (l1 < r1 && sl < n)
            l1++;
        while (l2 < r2 && sl < n)
            l2++;
        while (l3 < r3 && sl < n)
            l3++;
        while (l3 < r3 && sr > n)
            r3--;
        while (l2 < r2 && sr > n)
            r2--;
        while (l1 < r1 && sr > n)
            r1--;
    }

    cout << l1 << " " << l2 << " " << l3 << "\n";

    return 0;
}