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
        int n, e;
        cin >> n >> e;

        vector<int> a(n);
        for(int &x: a)
            cin >> x;

        vector<bool> prime(n);
        for(int i = 0; i < n; ++i){
            prime[i] = true;
            for(int j = 2; j * j <= a[i]; ++j)
                if(a[i] % j == 0){
                    prime[i] = false;
                    break;
                }
            if(a[i] == 1) prime[i] = false;
        }

        ll ans = 0;
        for(int i = 0; i <= e - 1; ++i){
            vector<int> v;
            for(int j = i; j < n; j += e)
                v.push_back(j);

            for(int i = 0; i < v.size(); ++i){
                if(a[v[i]] == 1 || !prime[v[i]]) continue;
                int l = i, r = i;
                while(l > 0 && a[v[l - 1]] == 1)
                    --l;
                while(r != (int)v.size() - 1 && a[v[r + 1]] == 1)
                    ++r;

                ans += (ll)(i - l + 1) * (r - i + 1) - 1;
            }
        }

        cout << ans << "\n";
    }
}