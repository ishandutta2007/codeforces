#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int cn[100];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    map<int, int> mp = {{4, 0}, {8, 1}, {15, 2}, {16, 3}, {23, 4}, {42, 5}};
 
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x = mp[x];
        if(x == 0 || cn[x] < cn[x - 1])
            cn[x]++;
    }
    cout << n - 6*cn[5] << '\n';
}