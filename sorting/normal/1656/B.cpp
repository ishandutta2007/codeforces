#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);
        for(ll &x: a)
            cin >> x;
        sort(all(a));

        ll ptr = 0;
        bool ok = false;
        for(int i = 0; i < n; ++i){
            while(ptr < n && a[i] - a[ptr] > k)
                ++ptr;
            if(ptr < n && a[i] - a[ptr] == k){
                ok = true;
                break;
            }
        }
        cout << ((ok) ? "YES" : "NO") << "\n";
    }
}