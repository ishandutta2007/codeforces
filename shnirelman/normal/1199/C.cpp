#include <bits/stdc++.h>

using namespace std;

vector<int> a;

int main() {
    int n, m;
    cin >> n >> m;

    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    m = m * 8 / n;

    if(m > 30) {
        cout << 0;
        return 0;
    }

    sort(a.begin(), a.end());

    set<int> st(a.begin(), a.end());

    int cur = 0, ind = 0;
    for(auto b : st) {
        while(ind < n && a[ind] == b) {
            a[ind] = cur;
            ind++;
        }
        cur++;
    }


    vector<int> s(n + 1, 0);
    s[1] = 1;
    for(int i = 2; i <= n; i++)
        s[i] = s[i - 1] + (a[i - 1] == a[i - 2] ? 0 : 1);

    int ans = n - 1;
    for(int i = 0; i < n; i++) {
        int l = i, r = n;
        while(r - l > 1) {
            int m1 = (r + l) / 2;
            //if(s[r] - s[l] <= (1ll << m)
            if(a[m1] - a[i] + 1 <= (1ll << m))
                l = m1;
            else
                r = m1;
        }

//        cout << i << ' ' << l << endl;

        ans = min(ans, i + n - l - 1);
    }

    cout << ans;
}