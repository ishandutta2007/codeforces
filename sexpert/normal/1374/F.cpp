#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[505], pos[505], cnt[505], n;
vector<int> op;

void shift(int i) {
    op.push_back(i);
    int x = a[i], y = a[i + 1], z = a[i + 2];
    pos[x] = i + 1;
    pos[y] = i + 2;
    pos[z] = i;
    a[i] = z;
    a[i + 1] = x;
    a[i + 2] = y;
}

void solve() {
    int n;
    cin >> n;
    
    vector<int> st;
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        st.push_back(a[i]);
    }
    sort(st.begin(), st.end());
    vector<int> sv = st;
    sv.erase(unique(sv.begin(), sv.end()), sv.end());
    map<int, int> conv;
    for(int i = 0; i < n; i++) {
        if(!conv.count(st[i]))
            conv[st[i]] = i + 1;
    }
    memset(cnt, 0, sizeof cnt);
    for(int i = 1; i <= n; i++) {
        cnt[a[i]]++;
        a[i] = conv[a[i]] + cnt[a[i]] - 1;
    }
    int inv = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(a[i] > a[j])
                inv++;
        }
    }
    if(inv % 2) {
        if(sv.size() == n) {
            cout << "-1\n";
            return;
        }
        int C = 0;
        for(int i = 1; i < st.size(); i++) {
            if(st[i] == st[i - 1]) {
                C = st[i];
                break;
            }
        }
        int tar = conv[C];
        for(int i = 1; i <= n; i++) {
            if(a[i] == tar)
                a[i] = tar + 1;
            else if(a[i] == tar + 1)
                a[i] = tar;
        }
    }
    op.clear();
    for(int i = 1; i <= n; i++)
        pos[a[i]] = i;
    for(int ps = n; ps >= 3; ps--) {
        while(pos[ps] != ps) {
            if(pos[ps] >= 2)
                shift(pos[ps] - 1);
            else
                shift(pos[ps]);
        }
    }
    cout << op.size() << '\n';
    for(auto x : op)
        cout << x << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--)
        solve();
}