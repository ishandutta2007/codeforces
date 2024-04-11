#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<int, int> cnt;
    vector<int> x(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i];
        ++cnt[x[i]];
    }

    int mn = cnt.begin()->first;
    int mx = cnt.rbegin()->first;

    if(mn + 1 >= mx){
        cout << n << "\n";
        for(int i = 0; i < n; ++i)
            cout << x[i] << " ";
        cout << "\n";
        return 0;
    }

    int mid = mx - 1;
    if(min(cnt[mn], cnt[mx]) < cnt[mid] / 2){
        int ans = n;
        ans -= (cnt[mid] / 2) * 2;
        cout << ans << "\n";
        
        cnt[mn] += cnt[mid] / 2;
        cnt[mx] += cnt[mid] / 2;
        cnt[mid] &= 1;
    }
    else{
        int ans = n;
        ans -= min(cnt[mn], cnt[mx]) * 2;
        cout << ans << "\n";

        int t = min(cnt[mn], cnt[mx]);
        cnt[mn] -= t;
        cnt[mx] -= t;
        cnt[mid] += 2 * t;
    }


    while(cnt[mn]--)
        cout << mn << " ";
    while(cnt[mx]--)
        cout << mx << " ";
    while(cnt[mid]--)
        cout << mid << " ";
    cout << "\n";
}