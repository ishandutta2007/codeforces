#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n , c[N] , d[N];

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d%d" , &c[i] , &d[i]);
    }
    int D = 0;
    int L = -1 << 30 , R = 1 << 30;
    for (int i = n - 1 ; i >= 0 ; -- i) {
        D -= c[i];
        if (d[i] == 1) {
            L = max(L , 1900 - D);
        } else {
            R = min(R , 1899 - D);
        }
    }
    if (L > R) cout << "Impossible" << endl;
    else if (R != 1 << 30) {
        cout << R << endl;
    } else {
        cout << "Infinity" << endl;
    }


}