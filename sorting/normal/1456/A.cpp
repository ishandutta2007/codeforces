#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9 + 3;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, p, k;
        cin >> n >> p >> k;

        string s;
        cin >> s;

        vector<bool> a(n + 1);
        for(int i = 1; i <= n; ++i)
            a[i] = (s[i - 1] == '1');

        int x, y;
        cin >> x >> y;

        int ans = INF;
        for(int i = 0; i < min(k, n - p + 1); ++i){
            int curr = 0;
            vector<bool> v;
            for(int j = p + i; j <= n; j += k){
               v.push_back(!a[j]);
               curr += !a[j];
            }

            curr *= x;
            curr += i * y;

            int add = 0, min_add = 0;
            for(int j = 0; j < (int)v.size() - 1; ++j){
                add += k * y;
                add -= v[j] * x;
                min_add = min(add, min_add);
            }

            ans = min(ans, curr + min_add);
        }

        cout << ans << "\n";
    }
}