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
        int n;
        cin >> n;

        vector<int> a(n + 2);
        for(int i = 0; i < n; ++i)
            cin >> a[i];

        int ans = n, cnt1 = 0, cnt0 = 0;
        for(int i = 0; i < n; ++i)
            cnt0 += a[i] == 0;

        for(int i = 0; i <= n; ++i){
            int cand;
            if(cnt1 >= cnt0)
                cand = cnt1;
            else
                cand = cnt0;
            check_min(ans, cand);

            cnt1 += a[i] == 1;
            cnt0 -= a[i] == 0;
        }
        cout << ans << "\n";
    }
}