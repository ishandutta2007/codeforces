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
        sort(all(a));

        if(a[0] == a[n - 1]){
            cout << n / 2 << "\n";
            continue;
        }

        ll ans = 0;
        map<int, int> cnt;
        for(int x: a)
            cnt[x]++;

        ll before = 0, after = n;
        for(auto [x, cnt_x]: cnt){
            before += cnt_x;
            after -= cnt_x;
            check_max(ans, before * after);
        }
        cout << ans << "\n";
    }
}