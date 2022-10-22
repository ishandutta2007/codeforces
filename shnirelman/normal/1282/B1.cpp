#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;

void solve() {
    int n, p, k;
    cin >> n >> p >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

//    for(auto a1 : a)
//        cout << a1 << ' ';
//    cout << endl;

    int ans = 0;
    int p1 = p;
    for(int i = 0; i < k; i++) {
        int cnt = 0;
        for(int j = i + k - 1; j < n; j += k) {
            if(a[j] <= p) {
                p -= a[j];
                cnt += k;
            } else
                break;
        }
        //cout << cnt << ' ' << p << endl;
        for(int j = 0; j < i; j++) {
            if(a[j] <= p) {
                cnt++;
                p -= a[j];
            } else
                break;
        }
//cout << cnt << ' ' << p << endl;
        if(cnt % k == i) {
            for(int j = cnt; j < n; j++)
                if(a[j] <= p) {
                    cnt++;
                    p -= a[j];
                } else
                    break;
        }

        //cout << "i: " << i << ' ' << cnt << endl;
        ans = max(ans, cnt);
        p = p1;
    }

    cout << ans << endl;

    /*int cnt = 0;
    for(int i = k - 1; i < n; i += k) {
        if(a[i] <= p) {
            cnt += k;
            p -= a[i];
        } else {
            break;
        }
    }

    for(int i = cnt; i < n; i++) {
        if(a[i] <= p) {
            cnt++;
            p -= a[i];
        } else {
            break;
        }
    }

    cout << cnt << endl;*/
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}