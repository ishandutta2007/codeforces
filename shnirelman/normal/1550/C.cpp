#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 200000 + 13;
const int M = 1e9 + 7;
const int B = 600;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = n;
    for(int i = 0; i < n; i++) {
        vector<int> up(1, 1), dw(1, 1);
        for(int j = i + 1; j < n; j++) {
            int rup = 1;
            for(int k = 0; k < up.size(); k++)
                if(a[i + k] <= a[j]) {
//                    if(i == 0 && j == 2) {
//                        cout << "ahgadjk;vn " << i + k <<' ' << up.size() << endl;
//                    }
                    rup = max(rup, up[k] + 1);
                }

            up.push_back(rup);

            int rdw = 1;
            for(int k = 0; k < dw.size(); k++)
                if(a[i + k] >= a[j])
                    rdw = max(rdw, dw[k] + 1);
            dw.push_back(rdw);

//            cout << i <<' ' << j << ' ' << rup << ' ' << rdw << ' ' << up.size()<< endl;

            if(rup >= 3 || rdw >= 3)
                break;
            ans++;
        }

    //        cout << i << ' ' << ans << endl;

    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}