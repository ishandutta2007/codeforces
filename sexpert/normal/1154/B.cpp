#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    if(a[0] == a[n - 1]) {
        cout << "0\n";
        return 0;
    }
    if((a[0] + a[n - 1])%2 == 0) {
        int d = (a[n - 1] - a[0])/2;
        for(int i = 0; i < n; i++) {
            if(a[i] != a[0] && a[i] != a[0] + d && a[i] != a[n - 1])
                break;
            if(i == n - 1){
                cout << d << '\n';
                return 0;
            }
        }
    }
    int d = a[n - 1] - a[0];
    for(int i = 0; i < n; i++) {
        if(a[i] != a[0] && a[i] != a[n - 1]){
            cout << "-1\n";
            return 0;
        }
    }
    cout << d << endl;
}