#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 1003;
int n, m;
pair<int, int> a[SZ];

void solve() {
    if (m < n || n == 2) {
        cout<<"-1\n";
        return;
    }
    int sum = 0;
    sort(a, a+n);
    for (int i = 0; i < n; i++) {
        sum += 2 * a[i].first;
    }
    sum += (a[0].first + a[1].first) * (m - n);
    cout<<sum<<"\n";
    for (int i = 0; i < n; i++) {
        cout<<a[i].second<<" "<<a[(i+1)%n].second<<"\n";
    }
    for (int i = 0; i < (m - n); i++) {
        cout<<a[0].second<<" "<<a[1].second<<"\n";
    }
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>m;
        for (int i = 0; i < n; i++) {
            cin>>a[i].first;
            a[i].second = i + 1;
        }
        solve();
    }
    
    return 0;
}