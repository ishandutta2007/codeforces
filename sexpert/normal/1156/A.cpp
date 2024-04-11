#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MAXN = 105;
int a[MAXN];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, tot = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) {
        if(a[i - 1] > 1 && a[i] > 1) {
            cout << "Infinite\n";
            return 0;
        }
        if(max(a[i - 1], a[i]) == 2) tot += 3;
        else tot += 4;
        if(i >= 2 && a[i] == 2 && a[i - 2] == 3) tot--;
    }
    cout << "Finite\n" << tot << endl;
}