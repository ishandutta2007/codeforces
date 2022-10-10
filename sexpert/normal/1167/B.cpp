#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int a[6];
int ans[4];
 
int main() {
    for(int i = 0; i < 4; i++) {
        cout << "? 1 " << i + 2 << '\n';
        cout.flush();
        cin >> ans[i];
    }
    a[0] = ans[0];
    for(int i = 1; i < 4; i++)
        a[0] = __gcd(a[0], ans[i]);
    if(a[0] == 30 || a[0] == 46)
        a[0] /= 2;
    for(int i = 0; i < 4; i++)
        a[i + 1] = ans[i]/a[0];
    a[5] = 108 - a[0] - a[1] - a[2] - a[3] - a[4];
    cout << "! " << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << " " << a[5] << '\n';
    cout.flush();
}