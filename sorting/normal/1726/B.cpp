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
        ll n, m;
        cin >> n >> m;

        if(m < n){
            cout << "No\n";
            continue;
        }
        if(m % n == 0 || (n & 1)){
            cout << "Yes\n";
            ll x = m / n;
            for(int i = 1; i < n; ++i)
                cout << x << " ";
            cout << x + (m % n) << "\n";
            continue;
        }
        if(m & 1){
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
        for(int i = 0; i < n - 2; ++i)
            cout << "1 ";
        ll x = (m - n + 2) / 2;
        cout << x << " " << x << "\n";
    }
}