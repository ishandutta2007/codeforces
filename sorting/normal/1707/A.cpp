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
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        for(int &x: a)
            cin >> x;

        auto check = [&](int mid){
            int curr_q = q;
            for(int i = mid; i < n; ++i){
                if(curr_q >= a[i])
                    continue;
                --curr_q;
            }
            return curr_q >= 0;
        };

        int l = 0, r = n;
        while(l != r){
            int mid = (l + r) >> 1;
            if(check(mid))
                r = mid;
            else
                l = mid + 1;
        }

        int ans = n - l;
        for(int i = 0; i < l; ++i)
            cout << (a[i] <= q);
        for(int i = l; i < n; ++i)
            cout << 1;
        cout << "\n";
    }
}