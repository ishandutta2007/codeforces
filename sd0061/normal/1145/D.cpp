#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0 ; i < n ; ++ i) {
        cin >> a[i];
    }
    cout << 2 + (a[2] ^ *min_element(a.begin() , a.end())) << endl;
}