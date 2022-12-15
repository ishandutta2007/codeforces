#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> x(n);
    for(int i = 0; i < n; ++i)
        cin >> x[i];

    int a;
    cin >> a;

    vector<int> c(n);
    for(int i = 0; i < n; ++i)
        cin >> c[i];
    
    vector<int> cnt(n);
    for(int i = 0; i < n; ++i){
        int rem  = max(0, x[i] - k);
        cnt[i] = rem / a + (bool)(rem % a);
    }

    int curr = 0;
    long long ans = 0;
    multiset<int> ms;
    for(int i = 0; i < n; ++i){
        ms.insert(c[i]);
        if(i + 1 < cnt[i]){
            cout << "-1\n";
            return 0;
        }

        while(curr < cnt[i]){
            auto it = ms.begin();
            curr++;
            ans += *it;
            ms.erase(it);
        }
    }

    cout << ans << "\n";
}