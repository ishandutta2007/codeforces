#include <bits/stdc++.h>
using namespace std;

int a[200005], n;
bool usado[200005];

int main() {
    cin >> n; 
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int k = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] >= k) {
            k++;
        }
    }
    cout << k - 1 << '\n';
    // Este es todo el cdigo del problema!
}