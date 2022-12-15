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

        int ans = 0;
        for(int i = 1; i <= n / 2 - 1; ++i)
            ans += (1 << i);
        for(int i = n / 2; i <= n - 1; ++i)
            ans -= (1 << i);
        ans += 1 << n;
        cout << ans << "\n";
    }
}