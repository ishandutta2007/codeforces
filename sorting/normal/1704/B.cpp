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
        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for(int &el: a)
            cin >> el;

        int mx = a[0], mn = a[0], ans = 0;
        for(int i = 1; i < n; ++i){
            check_max(mx, a[i]);
            check_min(mn, a[i]);
            if(mx - mn > 2 * x){
                ++ans;
                mx = mn = a[i];
            }
        }
        cout << ans << "\n";
    }
}