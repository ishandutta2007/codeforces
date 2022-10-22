#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int h[200005];
        for(int i = 0; i < n; i++) cin >> h[i];
        int u = h[0], l = h[0];
        bool f = true;
        for(int i = 1; i < n; i++){
            if(h[i] + k + k - 1 <= l || u + k <= h[i]) f = false;
            u = min(u, h[i]) + k - 1;
            l = max(l - (k - 1), h[i]);
        }
        if(f && l <= h[n - 1] && h[n - 1] <= u) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}