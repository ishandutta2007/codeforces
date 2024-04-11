#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int> (n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> v[i][j];
    vector<int> ans(n);
    bool kek = false;
    for(int i = 0; i < n; i++) {
        int m = 0;
        for(int j = 0; j < n; j++)
            m = max(m, v[i][j]);
        if(m < n - 1)
            ans[i] = m;
        else {
            if(!kek) {
                ans[i] = n - 1;
                kek = true;
            }
            else
                ans[i] = n;
        }
    }    
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << '\n';
}