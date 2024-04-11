#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--) {
        int a, b;
        cin >> a >> b;
        if((a + b) % 3 == 0 && max(a, b) - min(a, b) <= min(a, b))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}