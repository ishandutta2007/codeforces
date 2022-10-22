#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a, b;
    for(int i = 0; i < n; i++) {
        int t, x;
        cin >> t >> x;

        if(t == 1)
            a.push_back(x);
        else
            b.push_back(x);
    }

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    int sa = 0, sb = 0;
    for(auto x : a)
        sa += x;

    for(auto x : b)
        sb += x;

    int sa1 = 0;
    int ans = INF;
    for(int i = 0; i <= a.size(); i++) {
        int sb1 = 0;
        for(int j = 0; j <= b.size(); j++) {
            if(sa - sa1 + sb - sb1 <= i + j * 2) {
                ans = min(ans, i + j * 2);
            }
            if(j < b.size())
                sb1 += b[j];
        }
        if(i < a.size())
            sa1 += a[i];
    }

    cout << ans << endl;
}