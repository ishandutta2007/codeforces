#include <bits/stdc++.h>
using namespace std;

int main() {
    int n , a[100];
    cin >> n;
    for (int i = 0 ; i < n ; ++ i) {
        cin >> a[i];
    }
    cout << (*max_element(a , a + n) ^ a[n - 1]) << endl;
}