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
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> c(n);
        for(int i = 0; i < n; ++i){
            cin >> c[i];
            --c[i];
        }

        vector<int> cnt_l(n), cnt_r(n);
        for(int i = 0; i < l; ++i)
            cnt_l[c[i]]++;
        for(int i = l; i < n; ++i)
            cnt_r[c[i]]++;

        for(int i = 0; i < n; ++i){
            int mn = min(cnt_l[i], cnt_r[i]);
            cnt_l[i] -= mn;
            cnt_r[i] -= mn;
        }

        if(l >= r){
            swap(cnt_l, cnt_r);
            swap(l, r);
        }

        int cnt_match = 0;
        for(int i = 0; i < n; ++i)
            cnt_match += cnt_r[i] >> 1;

        int ans = 0;
        for(int i = 0; i < n; ++i)
            ans += cnt_l[i] + cnt_r[i];
        ans >>= 1;
        ans += (r - l) >> 1;
        ans -= min(cnt_match, (r - l) >> 1);

        cout << ans << "\n";
    }
}