#include <bits/stdc++.h>
using namespace std;

int a[1005];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int off = n - a[0];
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0)
            a[i] = (a[i] + off) % n;
        else
            a[i] = (a[i] - off + n) % n;
    }
    for(int i = 0; i < n; i++) {
        if(a[i] != i) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}