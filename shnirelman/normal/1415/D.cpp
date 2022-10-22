#include <bits/stdc++.h>

#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

const int M = 1e9 + 7;
const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int A = 26;
const int B = 300;

void solve() {

}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> mx(n);
    for(int i = 0; i < n; i++) {
        mx[i] = 0;
        for(int j = 0; j < 30; j++) {
            if((1 << j) & a[i]) {
                mx[i] = j;
            }
        }
    }

    for(int i = 0; i < n - 2; i++) {
        if(mx[i] == mx[i + 2]) {
            cout << 1 << endl;
            return 0;
        }
    }

    int ans = INF;
    for(int i = 0; i < n - 1; i++) {
        int s1 = 0;
        for(int j = 0; i - j >= 0; j++) {
            int s2 = 0;
            s1 ^= a[i - j];
            for(int k = 1; i + k < n; k++) {
                s2 ^= a[i + k];
                if(s1 > s2) {
                    ans = min(ans, j + k - 1);
//                    cout << i << ' ' << j << ' ' << k << ' ' << j + k - 1 << ' ' <<s1 << ' ' << s2 << endl;
                    break;
                }
            }

        }
    }

    cout << (ans == INF ? -1 : ans) << endl;
}