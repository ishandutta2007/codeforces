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
        vector<int> v(n);
        map<int, int> mp;
        for(int &x: v){
            cin >> x;
            ++mp[abs(x)];
        }

        int ans = 0;
        for(auto [x, cnt]: mp){
            ++ans;
            if(cnt >= 2 && x)
                ++ans;
        }
        cout << ans << "\n";
    }
}