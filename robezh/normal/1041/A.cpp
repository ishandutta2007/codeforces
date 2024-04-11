#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int num[1005];
    cin >> n;
    int mn = (int)1e9, mx = 0;
    for(int i = 0; i < n; i++){
        cin >> num[i];
        mx = max(mx, num[i]);
        mn = min(mn, num[i]);
    }
    cout << mx - mn + 1 - n;
}