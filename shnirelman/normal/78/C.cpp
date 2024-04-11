#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    bool fl = (k == 1 && m > 1);
    for(int i = 2; i * i <= m; i++) {
        if(m % i == 0) {
            if(m / i >= k)
                fl = true;
        }
    }



    if(n % 2 == 0 || !fl)
        cout << "Marsel";
    else
        cout << "Timur";

}