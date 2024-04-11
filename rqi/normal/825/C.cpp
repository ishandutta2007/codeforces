
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k, maxdif;
    cin >> n >> k;
    int difs[n];
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> difs[i];
    }
    sort(difs, difs+n);
    maxdif = k;
    for(int i = 0; i < n; i++){
            while(maxdif * 2 < difs[i]){
            maxdif = maxdif * 2;
            ans++;
            }
            maxdif = max(maxdif, difs[i]);
    }
    cout << ans;
}