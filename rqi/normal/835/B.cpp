#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    int u = 0;
    string n;
    int ans = 0;
    cin >> k >> n;
    int sorted[n.length()];
    int sum = 0;
    for(int i = 0; i < n.length(); i++){
        sorted[i] = n[i] - 48;
    }
    
    sort(sorted, sorted + n.length());
    for(int i = 0; i < n.length(); i++){
        sum += sorted[i];
        
    }
    while(sum < k){
        sum += (9 - sorted[u]);
        u++;
        ans ++;
    }
    cout << ans;
}