#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<ll> cou1(27, 0);
    for (int le = 0; le < 27; ++le) {
        int ones = (1 << (le + 1)) - 1;
        int top = (1 << le);
        int low = top * 2;
        int nex = low + top;
        
        vector<int> na(n);
        for (int i = 0; i < n; ++i) {
            na[i] = (a[i] & ones);
        }
        sort(na.begin(), na.end());
        
        /*for (int i = 0; i <= n; ++i) {
            cout << na[i] << " ";
        }*/
        
        int it = n - 1, il = n - 1, in = n - 1;
        for (int i = 0; i < n; ++i) {
            it = min(it + 1, n - 1);
            il = min(il + 1, n - 1);
            in = min(in + 1, n - 1);
            while (it > i && na[i] + na[it] >= top) {
                --it;
            }
            while (il > i && na[i] + na[il] >= low) {
                --il;
            }
            while (in > i && na[i] + na[in] >= nex) {
                --in;
            }
            //cout << "|" << it << " " << il << " " << in << "|";
            cou1[le] ^= ((il - it) & 1);
            cou1[le] ^= ((n - 1 - in) & 1);
        }
        //cout << cou1[le] << endl;
    }
    
    int ans = 0;
    for (int i = 0; i < 27; ++i) {
        ans += (cou1[i] << i);
    }
    cout << ans << "\n";
    
    return 0;
}