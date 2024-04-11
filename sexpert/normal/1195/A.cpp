#include <bits/stdc++.h>
using namespace std;
 
int ct[1005];
 
int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ct[x]++;
    }
    int bad = 0;
    for(int i = 1; i <= k; i++)
        if(ct[i] % 2) bad++;
    cout << n - bad/2 << '\n';
}