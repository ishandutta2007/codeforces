#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        if(k % 3 != 0)
            cout << (n % 3 == 0 ? "Bob\n" : "Alice\n");
        else {
            n %= (k + 1);
            if(n % 3 == 0 && n < k)
                cout << "Bob\n";
            else
                cout << "Alice\n";
        }
    }
}