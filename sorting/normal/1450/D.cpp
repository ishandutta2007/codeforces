#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> cnt(n + 1, 0);
        bool ok = true;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            cnt[a[i]]++;
            if(cnt[a[i]] >= 2)
                ok = false;
        }

        cout << ok;

        fill(cnt.begin(), cnt.end(), 0);

        int l = 0;
        cnt[a[0]]++;
        for(int i = 1; i < n; ++i){
            if(a[i] < a[i - 1]) break;
            cnt[a[i]]++;
            l = i;
        }

        int r = n - 1;
        cnt[a[n - 1]]++;
        for(int i = n - 2; i >= 0; --i){
            if(a[i] < a[i + 1]) break;
            cnt[a[i]]++;
            r = i;
        }

        int ans = 0;
        for(int i = 1; i <= n; ++i){
            if(!cnt[i]) break;
            if(cnt[i] >= 2){
                ans = i;
                break;
            }
            ans = i;
        }

        if(ans != n && !cnt[ans + 1] && (cnt[ans] == 1 || ans == 0)){
            for(int i = l + 1; i <= r - 1; ++i){
                if(a[i] == ans + 1){
                    ans++;
                    break;
                }
            }
        }

        for(int i = l + 1; i <= r - 1; ++i)
            ans = min(ans, a[i]);

        for(int i = n - 1; i >= 1; --i)
            cout << (i <= ans);
        cout << "\n";
    }
}