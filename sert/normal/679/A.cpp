#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;

const int a[19] = {2, 3, 5, 7, 4, 9, 25, 49, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
string s;
int d;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    for (int i = 0; i < 19 && d < 2; i++) {
        cout << a[i] << endl;
        cin >> s;
        if (s == "yes")
            d++;
    }

    if (d < 2)
        cout << "prime" << endl;
    else
        cout << "composite" << endl;

    return 0;
}