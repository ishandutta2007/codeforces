#include <bits/stdc++.h>
using namespace std;

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int a, b, c;
        cin >> a >> b >> c;
        int x = min({a, b / 2, c / 4});
        cout << x + 2 * x + 4 * x << "\n";
    
    return 0;
}