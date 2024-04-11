
// Problem : A. Polycarp's Pockets
// Contest : Codeforces Round #494 (Div. 3)
// URL : https://codeforces.com/contest/1003/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;

int cnt[101] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    int ret = 0;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        ret = max(ret, ++cnt[a]);
    }
    
    cout << ret << "\n";

    return 0;
}