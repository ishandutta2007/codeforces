#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, x = 1;
    cin >> n;
    vector <bool> vis(n+2, false);
    cout << '1';
    for(int i = 1, y; i <= n; i ++) {
        cin >> y;
        vis[n-y+1] = 1;
        while(vis[x] == 1) x ++;
        cout << ' ' << i-x+2;
    }
    cout << endl;
}