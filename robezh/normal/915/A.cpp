#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    int num[105];
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> num[i];
    int res = 10000000;
    for(int i = 0; i < n; i++){
        if(k % num[i] == 0) res = min(res, k / num[i]);
    }
    cout << res;
}