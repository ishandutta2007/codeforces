#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, l;
        cin >> n >> l;

        vector<int> a(n + 3);
        for(int i = 1; i <= n; ++i)
            cin >> a[i];

        a[0] = 0;
        a[n + 1] = l;

        array<long double, 2> t;
        long double time_l = 0, time_r = 0;
        int left = 1, right = n;
        t[0] = a[1] - a[0];
        t[1] = a[n + 1] - a[n];

        while(left <= right){
            if(t[0] + time_l < t[1] + time_r){
                time_l += t[0];
                left++;
                t[0] = (ld)(a[left] - a[left - 1]) / (ld)(left);
            }
            else{
                time_r += t[1];
                right--;
                t[1] = (ld)(a[right + 1] - a[right]) / (ld)(n + 1 - right);
            }
        }

        ld dist = a[left] - a[right];
        ld ans = 0;

        if(time_l < time_r)
            dist -= (ld)(left) * (time_r - time_l);
        else
            dist -= (ld)(n + 1 - right) * (time_l - time_r);

        ans = max(time_l, time_r);
        ans += (ld)(dist) / (ld)(left + n + 1 - right);

        cout << fixed << setprecision(9) << ans << "\n";
    }
}