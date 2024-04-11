#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 2e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, u, v;
        cin >> n >> u >> v;

        vector<int> a(n);
        for(int &x: a)
            cin >> x;

        int ans = INF;
        for(int i = 0; i < n - 1; ++i){
            if(abs(a[i] - a[i + 1]) >= 2) ans = 0;
            else if(abs(a[i] - a[i + 1]) == 1) ans = min(ans, min(u, v));
            else if(a[i] == a[i + 1]) ans = min(ans, v + min(u, v)); 
        }
        cout << ans << "\n";
    }
}