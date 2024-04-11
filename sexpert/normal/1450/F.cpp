#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a)
        cin >> x;

    vector<int> cnt(n + 1);
    int m_cnt = 0;
    for(auto &x : a) {
        cnt[x]++;
        if(cnt[x] > m_cnt)
            m_cnt = cnt[x];
    }

    if(m_cnt > n - m_cnt + 1) {
        cout << "-1\n";
        return;
    }

    a.push_back(a.back());
    vector<int> com;
    int ans = -1, pv = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] == a[i - 1]) {
            ans++;
            com.push_back(a[pv]);
            if(a[pv] != a[i - 1])
                com.push_back(a[i - 1]);
            pv = i;
        }
    }

    fill(cnt.begin(), cnt.end(), 0);
    m_cnt = 0;
    for(auto &x : com) {
        cnt[x]++;
        if(cnt[x] > m_cnt)
            m_cnt = cnt[x];
    }

    int A;
    for(int i = 1; i <= n; i++)
        if(cnt[i] == m_cnt)
            A = i;

    com.clear();
    pv = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] == a[i - 1]) {
            com.push_back(a[pv]);
            if(a[pv] != a[i - 1] && (a[pv] == A || a[i - 1] == A))
                com.push_back(a[i - 1]);
            pv = i;
        }
    }

    fill(cnt.begin(), cnt.end(), 0);
    m_cnt = 0;
    for(auto &x : com) {
        cnt[x]++;
        if(cnt[x] > m_cnt)
            m_cnt = cnt[x];
    }
    int oth = com.size() - m_cnt;

    //cout << m_cnt << " " << oth << '\n';

    if(m_cnt > oth + 1)
        ans += m_cnt - (oth + 1);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}