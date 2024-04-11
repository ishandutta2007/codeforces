#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e5 + 3;

int n, cnt[N], a[N];
int mn[103][2 * N]; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int mx = 0, cnt_mx = 0, mx_el;

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        cnt[a[i]]++;
        if(cnt[a[i]] > mx){
            mx = cnt[a[i]];
            cnt_mx = 1;
            mx_el = a[i];
        }
        else if(cnt[a[i]] == mx)
            cnt_mx++;
    }

    if(cnt_mx > 1){
        cout << n << '\n';
        return 0;
    }

    for(int i = 1; i <= min(n, 100); ++i)
        cnt[i] = 0;

    int ans = 0;
    for(int i = 1; i <= min(n, 100); ++i)
        mn[i][N] = 0;

    for(int i = 1; i <= n; ++i){
        cnt[a[i]]++;
        
        for(int j = 1; j <= min(n, 100); ++j){
            if(mx_el == j) continue;
            int diff = cnt[mx_el] - cnt[j] + N;
            if(diff == N){
                ans = max(ans, i);
                continue;
            }

            if(mn[j][diff])
                ans = max(ans, i - mn[j][diff]);
            else
                mn[j][diff] = i;
        }
    }

    cout << ans << "\n";
}