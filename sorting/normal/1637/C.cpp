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


        vector<int> a(n);
        for(int &x: a)
            cin >> x;

        if(n == 3 && a[1] & 1){
            cout << "-1\n";
            continue;
        }


        bool ok = false;
        ll ans = 0;
        for(int i = 1; i < n - 1; ++i){
            ok |= a[i] >= 2;
            ans += (a[i] + 1) / 2;
        }

        cout << (ok ? ans : -1) << "\n";
    }
}