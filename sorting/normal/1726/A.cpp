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

        if(n == 1){
            cout << "0\n";
            continue;
        }
        if(n == 2){
            cout << max(a[0], a[1]) - min(a[0], a[1]) << "\n";
            continue;
        }
        
        int ans = -3000;
        check_max(ans, a[n - 1] - a[0]);
        for(int i = 0; i < n; ++i){
            if(i != n - 1)
                check_max(ans, a[n - 1] - a[i]);
            else
                check_max(ans, a[n - 2] - a[n - 1]);
            if(i != 0)
                check_max(ans, a[i] - a[0]);
            else
                check_max(ans, a[0] - a[1]);
        }
        for(int i = 0; i < n; ++i){
            check_max(ans, a[(n - 1 + i) % n] - a[i]);
        }

        cout << ans << "\n";
    }
}