    #include <bits/stdc++.h>
    using namespace std;
     
    const int MAXN = 1e5 + 5;
    int cnt[MAXN];
    set<int> abv;
     
    int main() {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            int x, ans = 0;
            cin >> x;
            if(cnt[x] == 0)
                abv.insert(x);
            cnt[x]++;
            if(abv.size() == n) {
                ans = 1;
                for(int j = 1; j <= n; j++) {
                    cnt[j]--;
                    if(cnt[j] == 0)
                        abv.erase(j);
                }
            }
            cout << ans;
        }
        cout << endl;
    }