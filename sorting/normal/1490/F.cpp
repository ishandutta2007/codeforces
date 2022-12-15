#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        map<int, int> cnt;
        int n;
        cin >> n;

        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            cnt[x]++;
        }

        vector<int> v;
        for(auto [x, cnt_x]: cnt)
            v.push_back(cnt_x);

        int mx = *max_element(v.begin(), v.end());
        vector<int> v2(mx + 1);
        for(int x: v)
            v2[x]++;

        int c = 0, sz = v.size();
        int ans = accumulate(v.begin(), v.end(), 0), best_ans;
        best_ans = ans;
        for(int i = 0; i <= mx; ++i){
            ans += v2[i] * i;
            sz -= v2[i];
            ans -= sz;
            best_ans = min(best_ans, ans);
        }

        cout << best_ans << "\n";
    }
}