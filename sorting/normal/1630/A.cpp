#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 3;

int n, k;

void solve(){
    cin >> n >> k;

    vector<pair<int, int>> ans;
    if(k != n - 1){
        for(int i = 0; i < n / 2; ++i){
            if(i != 0 && i != n - 1 && i != k && i != n - 1 - k){
                ans.push_back({i, n - 1 - i});
                continue;
            }
        }
        ans.push_back({k, n - 1});
        if(k != 0) ans.push_back({0, n - 1 - k});
    }
    else{
        if(n == 4){
            cout << "-1\n";
            return;
        }

        for(int i = 0; i < n / 2; ++i){
            if(i != 0 && i != 1 && i != 3){
                ans.push_back({i, n - 1 - i});
                continue;
            }
        }
            ans.push_back({n - 2, n - 1});
            ans.push_back({0, n - 4});
            ans.push_back({1, 3});
    }

    for(auto [a, b]: ans)
        cout << a << " " << b << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();
}