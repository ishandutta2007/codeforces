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
        int n;
        cin >> n;

        vector<ll> a(n);
        for(ll &x: a)
            cin >> x;

        ll c = 1;
        for(ll &x: a){
            while(x % 2 == 0){
                c *= 2;
                x /= 2;
            }
        }

        sort(all(a));

        a.back() *= c;
        cout << accumulate(all(a), 0ll) << "\n";
    }
}