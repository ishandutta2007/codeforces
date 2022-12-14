#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int t, n;
pair<int,int> a[N];

void Enter() {
}

void Process() {
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        bool ok = true;
        cin >> n;
        for(int i=1; i<=n; ++i) cin >> a[i].first, a[i].second = i;
        sort(a+1, a+n+1);
        for(int i=1, ty=1; i<=n; ++i) {
            int j = i, odd = 0, even = 0;
            while (j<=n && a[i].first == a[j].first) {
                if (a[j].second & 1) odd++; else even++;
                ++j;
            }
            i = j-1;
            int w = min(odd, even);
            odd -= w, even -= w;
            if (odd == 1 && ty == 1 || even == 1 && ty == 0) ty ^= 1;
            else if (odd == 0 && even == 0) continue;
            else ok = false;
        }
        if (ok) cout << "YES\n"; else cout << "NO\n";
    }
}