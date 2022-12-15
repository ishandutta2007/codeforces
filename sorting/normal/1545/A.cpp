#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }

const int N = 1e5 + 3;

int cnt[2][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];

        for(int i = 0; i < n; ++i)
            cnt[i & 1][a[i]]++;

        sort(a.begin(), a.end());
        for(int i = 0; i < n; ++i)
            cnt[i & 1][a[i]]--;

        bool ok = true;
        for(int i = 0; i < n; ++i){
            if(cnt[0][a[i]] || cnt[1][a[i]]){
                ok = false;
                cnt[0][a[i]] = cnt[1][a[i]] = 0;
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
}