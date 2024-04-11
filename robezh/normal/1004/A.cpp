#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,d;
    int a[105];
    cin >> n >> d;
    int ans = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n-1; i++){
        if(a[i+1] - a[i] > 2 * d) ans += 2;
        else if(a[i+1] - a[i] == 2 * d) ans ++;
    }
    cout << ans + 2;
}